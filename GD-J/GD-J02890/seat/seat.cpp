//ad astra per aspera 
#include<bits/stdc++.h>

using namespace std;

int n,m,ci,R;
vector<int>st;

bool cmp(int a,int b){
	return a>b;
}
void init(){
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>ci;
		st.push_back(ci);
	}
	R=st[0];
//	cout<<R<<endl;
	std::sort(st.begin(),st.end(),cmp);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int nj;
			if((i+1)%2==0){
				nj=n-j-1;
			}else{
				nj=j;
			}
//			cout<<i<<" "<<j<<" "<<st[i*m+j]<<endl;
			if(st[i*m+j]==R){
				cout<<i+1<<" "<<nj+1;
				return;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("saet.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}//我也想优化但实力不允许啊啊啊