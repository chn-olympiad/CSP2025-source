#include<bits/stdc++.h>
using namespace std;
long n,t;
long sz[100010];
long long sm;
struct cy{
	long st1,st2,st3;
	long myd1,myd2,myd3;
}a[100010];
struct st{
	
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sm=0;
		for(int j=0;j<n;j++){
			cin>>a[i].st1>>a[i].st2>>a[i].st3;
			
		}
		cout<<sm<<endl;
	}
	return 0;
} 
