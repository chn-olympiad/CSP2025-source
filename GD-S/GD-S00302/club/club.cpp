#include<bits/stdc++.h>
using namespace std;
int t,n;
struct f{
	int a1,a2,a3;
}a[100005];
priority_queue<pair<int,int> >q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)q1.push({max(a[i].a2,a[i].a3)-a[i].a1,i});
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)q2.push({max(a[i].a1,a[i].a3)-a[i].a2,i});
			else q3.push({max(a[i].a2,a[i].a1)-a[i].a3,i});
		}
		while(q1.size()>n/2){
			int fir=q1.top().first,sec=q1.top().second;
			if(a[sec].a2>a[sec].a3)q2.push({1,sec});
			else q3.push({1,sec});
			q1.pop();
		}
		while(q2.size()>n/2){
			int fir=q2.top().first,sec=q2.top().second;
			if(a[sec].a1>a[sec].a3)q1.push({1,sec});
			else q3.push({1,sec});
			q2.pop();
		}
		while(q3.size()>n/2){
			int fir=q3.top().first,sec=q3.top().second;
			if(a[sec].a2>a[sec].a1)q2.push({1,sec});
			else q1.push({1,sec});
			q3.pop();
		}
		while(!q1.empty()){
			sum+=a[q1.top().second].a1;
			q1.pop();
		}
		while(!q2.empty()){
			sum+=a[q2.top().second].a2;
			q2.pop();
		}
		while(!q3.empty()){
			sum+=a[q3.top().second].a3;
			q3.pop();
		}
		cout<<sum<<endl;
	}
	return 0;
} 
