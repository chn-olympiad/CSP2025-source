#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int then[100005][3];
int tmp[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int n;
	long long ans;
	vector <int> n0,n1,n2;
	for(int ii=0;ii<T;ii++){
		cin>>n;
		ans=0;
		n0.clear();
		n1.clear();
		n2.clear();
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1] and a[i][0]>=a[i][2]){
				ans+=a[i][0];
				n0.push_back(i);
			}
			else if(a[i][1]>=a[i][0] and a[i][1]>=a[i][2]){
				ans+=a[i][1];
				n1.push_back(i);
			}
			else{
				ans+=a[i][2];
				n2.push_back(i);
			}
		}
		if(n0.size()>n/2){
			for(int i=0;i<n0.size();i++){
				tmp[i]=a[n0[i]][0]-max(a[n0[i]][1],a[n0[i]][2]);
			}
			sort(tmp,tmp+n0.size());
			for(int i=0;i<n0.size()-(n/2);i++){
				ans-=tmp[i];
			}
		}
		if(n1.size()>n/2){
			for(int i=0;i<n1.size();i++){
				tmp[i]=a[n1[i]][1]-max(a[n1[i]][0],a[n1[i]][2]);
			}
			sort(tmp,tmp+n1.size());
			for(int i=0;i<n1.size()-(n/2);i++){
				ans-=tmp[i];
			}
		}
		if(n2.size()>n/2){
			for(int i=0;i<n2.size();i++){
				tmp[i]=a[n2[i]][2]-max(a[n2[i]][0],a[n2[i]][1]);
			}
			sort(tmp,tmp+n2.size());
			for(int i=0;i<n2.size()-(n/2);i++){
				ans-=tmp[i];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
