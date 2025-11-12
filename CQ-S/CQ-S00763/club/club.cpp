#include <bits/stdc++.h>
using namespace std;
long long t,n,x,y,z,ans,dp[100005];
bool f=1;
struct u{
	long long a,b,c,id;
}a[100005];
struct o{
	long long d,id;
};
bool operator>(const o& __x, const o& __y){
	
	return __x.d > __y.d;
}
priority_queue<o,vector<o>,greater<o>>qa,qb,qc;
bool cmp(u s,u d){
	return s.a>d.a;
}

void DFS(long long i,long long k,long long a_cnt,long long b_cnt,long long c_cnt){
//	cout << i << ' ' << k << ' ' << a_cnt << ' ' << b_cnt << ' ' << c_cnt << '\n';
	if(i==n+1){
		ans=max(ans,k);
		return;
	}
//	if(k<=dp[i]&&dp[i]!=0){
//		return;
//	}
//	dp[i]=k;
	if(a_cnt<n/2&&a[i].a!=0){
		DFS(i+1,k+a[i].a,a_cnt+1,b_cnt,c_cnt);
	}
	if(b_cnt<n/2&&a[i].b!=0){
		DFS(i+1,k+a[i].b,a_cnt,b_cnt+1,c_cnt);
	}
	if(c_cnt<n/2&&a[i].c!=0){
		DFS(i+1,k+a[i].c,a_cnt,b_cnt,c_cnt+1);
	}
	DFS(i+1,k,a_cnt,b_cnt,c_cnt);
}

void pan(long long i){
	long long p=INT_MIN;
	if(qa.size()<n/2&&a[i].a>=a[i].b&&a[i].a>=a[i].c){
//		cout << "a" << ' ' << i << ' ' << qa.size() << '\n';
		qa.push({a[i].a,i});
	}else if(qb.size()<n/2&&a[i].b>=a[i].a&&a[i].b>=a[i].c){
//		cout << "b" << ' ' << i<< ' ' << qb.size() << '\n';
		qb.push({a[i].b,i});
	}else if(qc.size()<n/2&&a[i].c>=a[i].b&&a[i].c>=a[i].a){
//		cout << "c" << ' ' << i << ' ' << qc.size()<< '\n';
		qc.push({a[i].c,i});
	}else{
		if(qa.size()==0){
			x=a[i].a;
		}else{
			x=a[i].a-qa.top().d;
		}
		if(qb.size()==0){
			y=a[i].b;
		}else{
			y=a[i].b-qb.top().d;
		}
		if(qc.size()==0){
			z=a[i].c;
		}else{
			z=a[i].c-qc.top().d;
		}
		if(x>0&&x>=y&&x>=z){
//			cout << "d" << ' ' << i << '\n';
			p=qa.top().id;
			qa.push({a[i].a,i});
			qa.pop();
		}else if(y>0&&y>=x&&y>=z){
//			cout << "e" << ' ' << i << '\n';
			p=qb.top().id;
			qb.push({a[i].b,i});
			qb.pop();
		}else if(z>0&&z>=x&&z>=y){
//			cout << "f" << ' ' << i << '\n';
			p=qc.top().id;
			qc.push({a[i].c,i});
			qc.pop();
		}
	}
	if(p!=INT_MIN){
		pan(p);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		f=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].id=i;
			if(a[i].b!=0||a[i].c!=0){
				f=0;
			}
		}
		if(f){
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout << ans << '\n';
			continue;
		}
		if(n>15){
			for(int i=1;i<=n;i++){
				pan(i);
			}
			while(!qa.empty()){
				ans+=qa.top().d;
				qa.pop();
			}
			while(!qb.empty()){
				ans+=qb.top().d;
				qb.pop();
			}
			while(!qc.empty()){
				ans+=qc.top().d;
				qc.pop();
			}
			cout << ans << '\n';
		}else{
//			for(int i=1;i<=50;i++){
//				dp[i]=INT_MIN;
//			}
			DFS(1,0,0,0,0);
			cout << ans << '\n';
		}
		
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/
