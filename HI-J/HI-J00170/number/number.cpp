#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r"stdin);
    freopen("number.out","w"stdout);
	char s[1000000]={'@'};
	gets(s);
	int x=1,y=1;
	char a[1000000];
	while(1){
		if(s[x]>='0' and s[x]<='9'){
			a[x]=s[y];
			y++;
		}
		if(s[x]=='@'){
			break;
		}
		x++;
	}
	char b[y+1];
	char z='0'-1;
	int u;
	int n=y;
	for(int t=1;t<y;t++){
		z='0'-1;
		for(int i=1;i<=n;i++){
			if(a[i]>=z){
				z=a[i];
				u=i;
			}
		}
		n--;
		swap(a[u],a[n]);
		b[t]=z;
	}
	for(int i=1;i<=y;i++){
		cout<<b[i];
	}
	return 0;
    fclose(stdin);
    fclose(stdout);
	
}
