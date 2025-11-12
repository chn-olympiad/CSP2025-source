#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100001][4];
struct jie{
	int b;
	int v;
};
bool cmp1(const jie &x,const jie &y){
	return x.v-max(a[x.b][2],a[x.b][3])>y.v-max(a[y.b][2],a[y.b][3]);
}
bool cmp2(const jie &x,const jie &y){
//	if(x.v==y.v)
//		return max(a[x.b][1],a[x.b][3])<max(a[y.b][1],a[y.b][3]);
//	return x.v>y.v;
	return x.v-max(a[x.b][1],a[x.b][3])>y.v-max(a[y.b][1],a[y.b][3]);
}
bool cmp3(const jie &x,const jie &y){
	return x.v-max(a[x.b][2],a[x.b][1])>y.v-max(a[y.b][2],a[y.b][1]);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3]; 
	} 
	vector<jie> q1;
	vector<jie> q2;
	vector<jie> q3;
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
			q1.push_back({i,a[i][1]});
		} 
		else if(a[i][2]>a[i][1] && a[i][2]>a[i][3]){
			q2.push_back({i,a[i][2]});
		} 
		else{
			q3.push_back({i,a[i][3]});
		}
	} 
	if(q1.size()>n/2 || q2.size()>n/2 || q3.size()>n/2){
		int len1=-1,len2=-1,len3=-1;
		if(q1.size()>n/2){
			len1=q1.size()-1;
			sort(q1.begin(),q1.end(),cmp1);
			for(;len1+1>n/2;len1--){
				if(a[q1[len1].b][2]>a[q1[len1].b][3]){
					q2.push_back({q1[len1].b,a[q1[len1].b][2]});
				}
				else{
					q3.push_back({q1[len1].b,a[q1[len1].b][3]});
				}
			}
		}
		if(q2.size()>n/2){
			len2=q2.size()-1;
			sort(q2.begin(),q2.end(),cmp2);
			for(;len2+1>n/2;len2--){
				if(a[q2[len2].b][1]>a[q2[len2].b][3]){
					q1.push_back({q2[len2].b,a[q2[len2].b][1]} );
				}
				else{
					q3.push_back({q2[len2].b,a[q2[len2].b][3]});
				}
			}
		}
		if(q3.size()>n/2){
			len3=q3.size()-1;
			sort(q3.begin(),q3.end(),cmp3);
			for(;len3+1>n/2;len3--){
				if(a[q3[len3].b][2]>a[q3[len3].b][1]){
					q2.push_back({q3[len3].b,a[q3[len3].b][2]});
				}
				else{
					q1.push_back({q3[len3].b,a[q3[len3].b][1]});
				}
			}
		}
		int ans=0;
		if(len1!=-1){
			for(int i=0;i<n/2;i++){
				ans+=q1[i].v;
			}
			for(int i=0;i<q2.size();i++){
				ans+=q2[i].v;
			}
			for(int i=0;i<q3.size();i++){
				ans+=q3[i].v;
			}
		}
		else if(len2!=-1){
			for(int i=0;i<n/2;i++){
				ans+=q2[i].v;
			}
			for(int i=0;i<q1.size();i++){
				ans+=q1[i].v;
			}
			for(int i=0;i<q3.size();i++){
				ans+=q3[i].v;
			}
		}
		else{
			for(int i=0;i<n/2;i++){
				ans+=q3[i].v;
			}
			for(int i=0;i<q1.size();i++){
				ans+=q1[i].v;
			}
			for(int i=0;i<q2.size();i++){
				ans+=q2[i].v;
			}
		}
//		cout<<q1.size()<<' '<<q2.size()<<' '<<q3.size()<<endl;
		cout<<ans<<endl;
	}
	else{
		int ans=0;
		for(int i=0;i<q1.size();i++){
			ans+=q1[i].v;
		}
		for(int i=0;i<q2.size();i++){
			ans+=q2[i].v;
		}
		for(int i=0;i<q3.size();i++){
			ans+=q3[i].v;
		}
		cout<<ans<<endl;
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(;t--;){
		solve();
	} 
	return 0;
}
 
