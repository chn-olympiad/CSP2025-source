//GZ-S00486 贵阳市第十八中学 郭润山
#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z,mxpos,mnpos,maxa,mina;
}q[100005];
bool cmp(node a,node b){
	if(a.x==0 && a.y==0) return a.mina<b.mina;
	if(a.y==0 && a.z==0) return a.mina<b.mina;
	if(a.x==0 && a.z==0) return a.mina<b.mina;
	if(a.maxa==b.maxa) return a.mina>b.mina;
	return a.maxa>b.maxa;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		//清空 
		for(int i=1;i<=n;i++){
			q[i].x=0,q[i].y=0,q[i].z=0,q[i].maxa=0,q[i].mina=0;
		}
		cin>>n;
		int m=n/2;
		int cnt=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>q[i].x>>q[i].y>>q[i].z;
			q[i].maxa=max(max(q[i].x,q[i].y),q[i].z);
			if(q[i].x==q[i].maxa){ //判断最大 第二大 
				q[i].mxpos=1;
				if(q[i].y>q[i].z){
					q[i].mnpos=2;
					q[i].mina=q[i].y;
				}
				else{
					q[i].mnpos=3;
					q[i].mina=q[i].z;
				}
			}
			else if(q[i].y==q[i].maxa){
				q[i].mxpos=2;
				if(q[i].x>q[i].z){
					q[i].mnpos=1;
					q[i].mina=q[i].x;
				}
				else{
					q[i].mnpos=3;
					q[i].mina=q[i].z;
				}
			}
			else{
				q[i].mxpos=3;
				if(q[i].x>q[i].y){
					q[i].mnpos=1;
					q[i].mina=q[i].x;
				}
				else{
					q[i].mnpos=2;
					q[i].mina=q[i].y;
				}
			}
		}
		if(n==2){
			if(q[1].mxpos==q[2].mxpos){
				if(q[1].mina>q[2].mina){
					cout<<q[2].maxa+q[1].mina<<endl;
				}
				else{
					cout<<q[1].maxa+q[2].mina<<endl;
				} 
				break;
			}
		}
		sort(q+1,q+n+1,cmp); 
		for(int i=1;i<=n;i++){ //累加 
			if(q[i].mxpos=1){ //1
				if(cnt1>=m){
					cnt+=q[i].mina;
					if(q[i].mnpos=2) cnt2++;
					if(q[i].mnpos=3) cnt3++;
				}
				else{
					cnt+=q[i].maxa;
					cnt1++;
				}
			}
			else if(q[i].mxpos=2){ //2
				if(cnt2>=m){
					cnt+=q[i].mina;
					if(q[i].mnpos=1) cnt1++;
					if(q[i].mnpos=3) cnt3++;
				}
				else{
					cnt+=q[i].maxa;
					cnt2++;
				}
			}
			else if(q[i].mxpos=3){ //3
				if(cnt3>=m){
					cnt+=q[i].mina;
					if(q[i].mnpos=1) cnt1++;
					if(q[i].mnpos=3) cnt3++;
				}
				else{
					cnt+=q[i].maxa;
					cnt3++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
