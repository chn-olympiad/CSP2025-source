#include<bits/stdc++.h>
using namespace std;
int a[500005],b;
long long c,d,ans,e,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>b>>c;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	for(int i=0;i<b;i++){
		d=0;
		for(int j=i;j<b;j++){
			if(j==i){
				d=a[j];
			}
			else{
				d=d^a[j];
			}
			if(d==c){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
