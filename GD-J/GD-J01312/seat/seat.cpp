#include <bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	
	int n,m,tgt,tgt_index,ans_x,ans_y;
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>a[i];
	}
	tgt=a[0];
	sort(a,a+n*m,cmp);

	for (int i=0;i<n*m;i++){
		if (a[i]==tgt){
			tgt_index=i+1;
			break;
		}
	}

	ans_x=(tgt_index-1)/m+1;

	int cur_first; 
	if (ans_x&1){
		cur_first=(ans_x-1)*m+1;
		ans_y=tgt_index-cur_first+1;
	}
	else{
		cur_first=ans_x*m;
		
		ans_y=cur_first-tgt_index+1;
	}
	
	
	cout<<ans_x<<' '<<ans_y;

	return 0;
}
