//GZ-S00013 贵州省黔西第一中学 代毅承 
#include<bits/stdc++.h>
using namespace std;
string a[200005],que;
long long n,m,q,num=0;
int f(int h,int e){
	string hd;
	for(int i=h;i<=e;i++){
		hd=hd+que[i];
	}
	for(int i=0;i<=n*2;i=i+2){
		if(hd==a[i]){		
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<=n*2;i=i+2){
		cin>>a[i]>>a[i+1];
	}
	for(int i=0;i<q;i++){
		cin>>que;
		num=0;
		int b=que.size();
		for(int j=0;j<b;j++){
			for(int v=j;v<b;v++){
				if(f(j,v)){
					num++;
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		cout<<"0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
