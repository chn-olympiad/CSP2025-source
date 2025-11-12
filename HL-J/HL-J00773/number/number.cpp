#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[100000],x=0,y=0;
	int n=0;
	while(1){
		if(s[n]=='\0'){
			break;
		}else{
			n++;
		}
	}
	for(int i=0;i<=n;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[x]=s[i]-48;
			x++;

		}
	}
	for(int i=0;i<=x-1;i++){
		for(int j=0;j<=x-1;j++){
			if(a[i]<=a[j+1+i]){
				int t;
				t=a[i];
				a[i]=a[j+1+i];
				a[j+1+i]=t;
			}
		}
	}
	for(int i=0;i<=x-1;i++){
		if(a[i]==0){
			y++;
		}
	}
	if(y==x){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=x-1;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
