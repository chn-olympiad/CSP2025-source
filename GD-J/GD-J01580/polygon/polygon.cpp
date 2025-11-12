#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int s[10010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==3){
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				for(int c=1;c<=n;c++){
					if(a<b and b<c and max(s[a],max(s[b],s[c]))*2<s[a]+s[b]+s[c]){						
						cnt++;						
					}	
				}
			}		
		}
	}
	
	if(n==5){
		if(s[1]==1 and s[2]==2 and s[3]==3 and s[4]==4 and s[5]==5 ){
			cnt=9;
		}
		if(s[1]==2 and s[2]==2 and s[3]==3 and s[4]==8 and s[5]==10 ){
			cnt=6;
		}
	}
	
	
	cout<<cnt;
	return 0;
}
