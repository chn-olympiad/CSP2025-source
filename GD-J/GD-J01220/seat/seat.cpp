#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,cnt=0;
	cin>>n>>m;	//n:行,m:列 
	vector<int> vec(n*m);
	for(auto &v:vec){
		cin>>v;
	}
	for(int i=1;i<=vec.size();i++){
		if(vec[i-1]==i){
			cnt++;
		}
	}
	if(cnt==vec.size()){
		cout<<m<<' '<<n;
		return 0;
	}
	int R=vec[0]; 
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=1;i<=vec.size();i++){
		if(vec[i-1]==R){
			if(i<=n){
				cout<<1<<' '<<i;
				return 0;
			}else if(i>n){ 
				int tmp=i/n,t_hang,t_lie;	//判断从头还是从尾开算 
				if(tmp&1){	//如果为奇数，从末尾开算 
					t_hang=tmp+1;
					t_lie=i%n+m-1;
				}else{	//如果为偶数，从开头开算 
					t_hang=i%n;
					t_lie=tmp+1;
				}
				cout<<t_lie<<' '<<t_hang;
			}
		}
	}
	
//	for(auto v:vec){
//		cout<<v<<' ';
//	}
//	cout<<endl<<R;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
