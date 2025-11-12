#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
这似乎是数学
座位一共100 
我们可以用结构体存储标号，到时候找
每个人的成绩都不一样
（map可以排序吗？） 
1.写入
2.进行模拟，也就是说自动填充座位
3.找到people 


代码 

AC
*/
int n,m;//RC
int a[1000][1000];
int cnt=0;//计数器
struct Stu{
	int score;
	int no; 
}; 
vector<Stu> v;//由于普通的sort被破坏，用vector 
bool cmp(Stu a,Stu b){
	if(a.score>b.score) return true;
	else return false;
}
int r=1,c=1;//lie hang
signed main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
	v.push_back({1e9,0});//从1开始 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			int x;
			cin>>x;
			v.push_back({x,cnt});
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<v[i].score<<" "<<v[i].no<<endl;
//	}
	sort(v.begin(),v.end(),cmp);
//	for(int i=1;i<=cnt;i++){
//		cout<<v[i].score<<" "<<v[i].no<<endl;
//	}
    bool f=1; //1=向下，0=向上 
	for(int i=1;i<=cnt;i++){
		a[c][r]=i;
		if(v[i].no==1){
			break;
		}
		if(f){
			if(c==n){
				r++;
				f=0;
				continue;
			}
			c++;
		}else{
			if(c==1){
				r++;
				f=1;
				continue;
			}
			c--;
		}
		 
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<r<<" "<<c;
	return 0;
}

