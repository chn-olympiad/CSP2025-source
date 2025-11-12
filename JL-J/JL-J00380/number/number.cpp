#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<n;i++){
		s=a[i];
		}
		for(int i=0;i<n;i++){
			if(0<=a[i]||a[i]<=9){
				a[i]+=ans;
				}else{
					return 1;
					}
			}
			for(int i=0;i<n;i++){
				cout<<ans;
				}
	return 0;
	}
