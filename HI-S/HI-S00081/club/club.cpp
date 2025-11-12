#include<bits/stdc++.h>
using namespace std;
int t;
int n,jg;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		jg=0;
		cin>>n;
		int a1[100005],a2[100005],a3[100005];
		for(int j=0;j<n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
			int amax=max(a1[j],max(a2[j],a3[j]));
			jg=jg+amax;
		}
		cout<<jg<<endl;
	}
	
	return 0;
}
