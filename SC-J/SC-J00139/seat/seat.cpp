#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<int> sc;
	int n,m,cnt;cin>>n>>m;
	int r,t;cin>>r;sc.push_back(r);
	
	for(int i=1;i<n*m;++i){
		cin>>t;
		sc.push_back(t);
	}
	sort(sc.begin(),sc.end(),greater<int>());
	//输出：先列后行     
	//1,1-1,2-1,3-....-1,n-2,n,2,n-1,....2,1为一个循环 
	//判断奇偶 列m行n
	for(int i=0;i<sc.size();++i){
		if(sc[i]==r){
			cnt=i;
		}
	} 
	int x=1,y=1;//x列y行 
	while(cnt--){
		if(x%2==1){
			if(y<n){y++;}
			else{x++;}
		}
		else{
			if(y>1){y--;}
			else{x++;}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}