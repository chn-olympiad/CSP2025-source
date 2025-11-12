#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
struct node{
	int x[100005];
	vector<int>v;
}a[4];
bool cmp1(int q,int h){
	return max(a[2].x[q]-a[1].x[q],a[2].x[q]-a[1].x[q])<max(a[2].x[h]-a[1].x[h],a[2].x[h]-a[1].x[h]);
}
bool cmp2(int q,int h){
	return max(a[1].x[q]-a[2].x[q],a[3].x[q]-a[2].x[q])<max(a[1].x[h]-a[2].x[h],a[3].x[h]-a[2].x[h]);
}
bool cmp3(int q,int h){
	return max(a[1].x[q]-a[3].x[q],a[2].x[q]-a[3].x[q])<max(a[1].x[h]-a[3].x[h],a[2].x[h]-a[3].x[h]);
}
void work(){
	a[1].v.clear();
	a[2].v.clear();
	a[3].v.clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1].x[i]>>a[2].x[i]>>a[3].x[i];
		if(max(a[1].x[i],max(a[2].x[i],a[3].x[i]))==a[1].x[i]){
			a[1].v.push_back(i);
		}else if(max(a[1].x[i],max(a[2].x[i],a[3].x[i]))==a[2].x[i]){
			a[2].v.push_back(i);
		}else{
			a[3].v.push_back(i);
		}
	}
	int len1=a[1].v.size();
	int len2=a[2].v.size();
	int len3=a[3].v.size();
	if(a[1].v.size()>n/2){
		sort(a[1].v.begin(),a[1].v.end(),cmp1);
		while(len1>n/2){
			int i=a[1].v[len1-1];
			if(a[2].x[i]-a[1].x[i]>a[3].x[i]-a[1].x[i]){
				len1--;
				if(len2>=n/2){
					len3++;
					a[3].v.push_back(i);
				}else{
					len2++;
					a[2].v.push_back(i);
				}
			}else{
				len1--;
				if(len3>=n/2){
					len2++;
					a[2].v.push_back(i);
				}else{
					len3++;
					a[3].v.push_back(i);
				}
			}
		}
	}
	if(a[2].v.size()>n/2){
		sort(a[2].v.begin(),a[2].v.end(),cmp2);
		while(len2>n/2){
			int i=a[2].v[len2-1];
			if(a[1].x[i]-a[2].x[i]>a[3].x[i]-a[2].x[i]){
				len2--;
				if(len1>=n/2){
					len3++;
					a[3].v.push_back(i);
				}else{
					len1++;
					a[1].v.push_back(i);
				}
			}else{
				len2--;
				if(len3>=n/2){
					len1++;
					a[1].v.push_back(i);
				}else{
					len3++;
					a[3].v.push_back(i);
				}
			}
		}
	}
	if(a[3].v.size()>n/2){
		sort(a[3].v.begin(),a[3].v.end(),cmp3);
		while(len3>n/2){
			int i=a[3].v[len3-1];
			if(a[1].x[i]-a[3].x[i]>a[2].x[i]-a[3].x[i]){
				len3--;
				if(len1>=n/2){
					len2++;
					a[2].v.push_back(i);
				}else{
					len1++;
					a[1].v.push_back(i);
				}
			}else{
				len3--;
				if(len2>=n/2){
					len1++;
					a[1].v.push_back(i);
				}else{
					len2++;
					a[2].v.push_back(i);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<len1;i++){
		int t=a[1].v[i];
		ans+=a[1].x[t];
	}
	for(int i=0;i<len2;i++){
		int t=a[2].v[i];
		ans+=a[2].x[t];
	}
	for(int i=0;i<len3;i++){
		int t=a[3].v[i];
		ans+=a[3].x[t];
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
