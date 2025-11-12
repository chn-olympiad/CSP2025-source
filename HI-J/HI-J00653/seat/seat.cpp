#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
int c=0,r=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int cs=0;
    scanf("%d%d",&n,&m);
    cin>>s[1];
    if(n==1&&m==1){
    	cout<<"1 1";
    	return 0;
	}
    c=s[1];
    for(int i=2;i<=n*m;i++){
    	cin>>s[i];
	}
	sort(s+n*m,s+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(s[i]<s[i+1]){
			swap(s[i],s[i+1]);
		}
	}
	for(int i=1;i<=n*m;i++){
		r++;
		if(s[i]==c){
			break;
		}
	}
	cs=r;
	r=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cs--;
			if(cs==0){
				r=j;
				if(m%2==1){
					c=i;
				}
				else{
					c=n-i+1;
				}
				break;
			}
		}
		
	}
	printf("%d ",c);
	printf("%d",r);
	return 0;
}

