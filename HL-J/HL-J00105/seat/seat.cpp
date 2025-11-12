#include<bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	int id;
	int pai;
}p[105];
bool cmp(stu a,stu b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;	
	int q=n*m;
	for(int i=1;i<=q;i++){
		cin>>p[i].score;
		p[i].id=i;
	}
	sort(p+1,p+q+1,cmp);
	for(int i=1;i<=q;i++){
		p[i].pai=i;
	}
	int ans_id;
	for(int i=1;i<=q;i++){
		if(p[i].id==1){
			ans_id=p[i].pai;
		}
	}
	bool flag=1,flag1=0;
	int ans=1;
	for(int i=1;i<=m;i++){
		if(flag1){
			break;
		}
		if(flag){
			for(int j=1;j<=n;j++){
				if(ans_id==ans){
					cout<<i<<" "<<j;
					flag1=1;
					break;
				}
				ans++;
			}
			flag=0;
		}else{
			for(int j=n;j>=1;j--){
				if(ans_id==ans){
					cout<<i<<" "<<j;
					flag1=1;
					break;
				}
				ans++;
			}
			flag=1;
		}
	}
	return 0;
}
