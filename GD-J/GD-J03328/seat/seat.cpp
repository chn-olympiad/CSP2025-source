#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,tol=0;
	cin>>n>>m;
	stack<int>tmp1,tmp2;
	int score[n*m];
	for(int a=1;a<=n*m;a++){
	
			tol++;
			cin>>score[a];
			r=score[1];
			}
	if(n==1&&m==1){
		cout<<r;
		return 0;
	}
	int tmp=n*m+1;
	sort(score,score+tmp,cmp);
	int ans[n][m];
	
	if(m==1){
		for(int a=1;a<=n;a++){
			if(r==score[a]){
				cout<<1<<" "<<a;
				return 0;
			}
		}
	}
	if(n==1){
		for(int a=1;a<=m;a++){
			if(r==score[a]){
				cout<<a<<" "<<1;
				return 0;
			}
		}
	}
	for(int a=n;a>0;a--){
		tmp1.push(a);
	}
	int b=0;
	for(int a=1;a<=m;a++){
		
		if(tmp2.empty()){
			while(!tmp1.empty()){
				tmp2.push(tmp1.top());
				b++;
				ans[a][tmp1.top()]=score[b];
				if(ans[a][tmp1.top()]==r){
					cout<<a<<" "<<tmp1.top();
					return 0;
				}
				tmp1.pop();
			}
		}
	
		if(tmp1.empty()){
			while(!tmp2.empty()){
				tmp1.push(tmp2.top());
				b++;
				ans[a][tmp2.top()]=score[b];
					if(ans[a][tmp2.top()]==r){
					cout<<a<<" "<<tmp2.top();
					return 0;
				}
				tmp2.pop();
			}
		}
		
	}
	
}
