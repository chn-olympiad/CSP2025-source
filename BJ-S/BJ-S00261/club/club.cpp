#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		int a[100005]={0};
		for(int i=0;i<n;i++)
			scanf("%d 0 0\n",&a[i]);
		sort(a,a+n,greater<int>());
		int s=0;
		for(int i=0;i*2<n;i++)
			s+=a[i];
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
