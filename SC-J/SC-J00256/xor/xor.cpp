#include<bits/stdc++.h>
using namespace std;
long long n,k,l[1000000],s=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>l[i];
			if(l[i]==1){
				s++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>l[i];
			if(l[i]==0){
				s++;
			}else if(l[i]==1&&l[i-1]==1){
				l[i]=-1;
				l[i-1]=-1;
				s++;
			}
		}
	}
	cout<<s<<endl;
	return 0;
}