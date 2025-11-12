#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//有点难这道 吓哭了 

ll g[5010];//木棍长度 
ll n;
ll cnt = 0;

ll bfs(vector<ll>a,ll sum,ll deep){
	//cout<<sum<<' '<<deep<<endl;////
	//for(int i = 0;i<a.size();i++)cout<<a[i]<<' ';////
	//cout<<endl;////
	if(deep==1){//根部 
		for(ll i = 1;i<=n-2;i++)//枚举下一位所有可能 
		{
			a.push_back(i);
			//cout<<"into"<<i<<' '<<endl;////
			bfs(a,sum+g[i],deep+1);
			//cout<<"rootc";////
			a.erase(a.begin());//恢复 
			sum-=g[i];
		}
		
		return 0;
	}
	
	//子部 // a[a.size()-1] 为末位 
	if(deep >= 3){//可构成多边形
		ll ss = 0;
		for(ll i = 0;i<a.size();i++)ss+=a[i];
		if(ss>2*g[a[a.size()-1]]){
			cnt+=1;
		}
		/*else{
			cout<<"sum"<<sum<<" g"<<a[a.size()-1]<<' ';////
			for(int i = 0;i<a.size();i++)cout<<a[i]<<' ';////
			cout<<endl;////
		}//*/
	}
	
	if(a[a.size()-1] >= n){//不能再往下拓展了
		//cout<<"out"<<endl;////
		return 0; 
	}
	for(ll i = a[a.size()-1]+1 ; i<=n ;i++)//枚举下一位所有可能,【最末位下标+1，n】这个是下一位的下标 
	{
		//cout<<endl<<(bool)(i<=n)<<endl;
		a.push_back(i);
		bfs(a,sum+g[i],deep++);
		a.erase(a.begin()+deep-1);//恢复 
		sum-=g[i];
	}
	return 0;
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(ll i = 1;i<=n;i++){
		cin>>g[i];
	}
	sort(g,g+n);//升序排序 
	
	if(n==3){//骗分
		if(g[1]+g[2]+g[3]>g[3]*2) {
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;//骗完就跑路 
	}//##
	
	vector<ll>com;
	bfs(com,0,1);
	cout<<cnt;
	
}
