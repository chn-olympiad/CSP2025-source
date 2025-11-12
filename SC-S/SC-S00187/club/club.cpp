#include<bits/stdc++.h>
using namespace std;

struct node{
	int man,d,cha=0;
	//man为满意度，d是部门
};

bool cmp(const node &x,const node &y){
	return x.man>y.man;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		vector<vector<node> > A(n);
		int x=0,y=0,z=0,sum=0;//分别表示部门1,2,3被最喜欢的人数
		for(int i=0,a,b,c;i<n;i++){
			cin>>a>>b>>c;
			A[i].push_back({a,1});
			A[i].push_back({b,2});
			A[i].push_back({c,3});
			sort(A[i].begin(),A[i].end(),cmp);
			if(A[i][0].d==1) x++;
			else if(A[i][0].d==2) y++;
			else z++;
			sum += A[i][0].man;
			A[i][0].cha = A[i][0].man - A[i][1].man;//记录最大的满意度与第二大的满意度的差值
		}
		if(x>n/2){
			//人数多了，就需要让他们去其他的部门
			int cnt = x-n/2;//记录多了多少人
			//考虑哪些要出去
			vector<int> N;
			for(int i=0;i<n;i++){
				if(A[i][0].d==1){
					N.push_back(A[i][0].cha);
				}
			}
			sort(N.begin(),N.end());
			for(int i=0;i<cnt;i++){
				sum-=N[i];
			}//让他们去第二满意的
		}
		
		else if(y>n/2){
			//人数多了，就需要让他们去其他的部门
			int cnt = y-n/2;//记录多了多少人
			//考虑哪些要出去
			vector<int> N;
			for(int i=0;i<n;i++){
				if(A[i][0].d==2){
					N.push_back(A[i][0].cha);
				}
			}
			sort(N.begin(),N.end());
			for(int i=0;i<cnt;i++){
				sum-=N[i];
			}//让他们去第二满意的
		}
		
		else if(z>n/2){
			//人数多了，就需要让他们去其他的部门
			int cnt = z-n/2;//记录多了多少人
			//考虑哪些要出去
			vector<int> N;
			for(int i=0;i<n;i++){
				if(A[i][0].d==3){
					N.push_back(A[i][0].cha);
				}
			}
			sort(N.begin(),N.end());
			for(int i=0;i<cnt;i++){
				sum-=N[i];
			}//让他们去第二满意的
		}
		
		cout<<sum<<"\n";
	}
	return 0;
}