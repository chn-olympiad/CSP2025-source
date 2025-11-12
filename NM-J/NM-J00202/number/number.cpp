#include<bits/stdc++.h>
using namespace std;
long long a[1000010],b[1000010];
int s;
long long d[1000010];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int i;
    cin>>s;
    int k=0,y=0;
    int lens=s, size();
    for(int i=0;i<lens;i++){
        if(s[d]>='0' and s[d]<='9')
            {
          a[k]=s[d]-'0';
          k++;
        }
        y++;
    }
    sort(a-y,a+i-y);
    for(int i=0;i<k;i++){
	a[i]=b[i];


	}
    sort(b,b+i);
    for(i=k;i>=0;i--){
    	b[i]=a[i] ;
	}
     for(i=0;i<k;i++){
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}

