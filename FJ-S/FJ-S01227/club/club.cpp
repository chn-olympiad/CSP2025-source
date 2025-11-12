#include<bits/stdc++.h>
using namespace std;
int n,a[100005][3],s[100005];
int ma(int o,int p,int q){
	return max(o,max(p,q));
}
int read(){
	int l=0;
	char k=getchar();
	while(k>='0'&&k<='9'){
		l=l*10+(k-'0');
		k=getchar();
	}
	return l;
}
vector<int> q1,q2,q3; 
void work(){
	q1.clear();
	q2.clear();
	q3.clear();
	n=read();
	for(int i=1;i<=n;i++){
		//cin>>a[i][0]>>a[i][1]>>a[i][2];
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		//cout<<a[i][0]<<a[i][1]<<a[i][2]<<endl;
	}
	for(int i=1;i<=n;i++){
		int mx=ma(a[i][0],a[i][1],a[i][2]);
		if(mx==a[i][0]){
			q1.push_back(i);
		}else if(mx==a[i][1]){
			q2.push_back(i);
		}else{
			q3.push_back(i);
		}
	}
//	cout<<1<<endl;
	int ans=0;
	if(q1.size()>n/2){
		int sz=q1.size();
		for(int i=0;i<sz;i++){
			s[i]=min(a[q1[i]][0]-a[q1[i]][1],a[q1[i]][0]-a[q1[i]][2]);
		}
		sort(s,s+sz);
		for(int i=0;i<sz-n/2;i++){
			ans-=s[i];
		}
	}if(q2.size()>n/2){
		int sz=q2.size();
		for(int i=0;i<sz;i++){
			s[i]=min(a[q2[i]][1]-a[q2[i]][0],a[q2[i]][1]-a[q2[i]][2]);
		}
		sort(s,s+sz);
		for(int i=0;i<sz-n/2;i++){
			ans-=s[i];
		}
	}
	if(q3.size()>n/2){
		int sz=q3.size();
		for(int i=0;i<sz;i++){
			s[i]=min(a[q3[i]][2]-a[q3[i]][1],a[q3[i]][2]-a[q3[i]][0]);
		}
		sort(s,s+sz);
		for(int i=0;i<sz-n/2;i++){
			ans-=s[i];
		}
	}
	//cout<<2<<endl;
	for(int i=0;i<q2.size();i++){
			ans+=a[q2[i]][1];
		}
		for(int i=0;i<q3.size();i++){
			ans+=a[q3[i]][2];
		}
	for(int i=0;i<q1.size();i++){
			ans+=a[q1[i]][0];
		}
//	cout<<3<<endl;
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--) work();
	//15:09切了，感觉大样例有点超时 15:19写了快读，应该能100pts 
	return 0;
}

