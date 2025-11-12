#include<bits/stdc++.h>
using namespace std;
struct stu{
	int num,lo,sml;
};
bool operator < (stu a,stu b){
	return a.lo>b.lo;
}
int a[100005][4];
priority_queue<stu> q1,q2,q3;
int main(){
	/*freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);*/
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int lk=n/2;
		for(int j=1;j<=n;j++)
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		for(int j=1;j<=n;j++){
			if(a[j][1]>a[j][2]&&a[j][1]>a[j][3]){
				if(q1.size()+1>lk){
					if((q1.top().lo-q1.top().sml)<(a[j][1]-max(a[j][2],a[j][3]))){
						int num1=q1.top().num;
						q1.pop();
						n++;
						a[n][1]=0;
						a[n][2]=a[num1][2];
						a[n][3]=a[num1][3];
						stu k;k.lo=a[j][1];
						k.sml=max(a[j][2],a[j][3]);
						k.num=j;q1.push(k);
					}else{
						n++;
						a[n][1]=0;
						a[n][2]=a[j][2];
						a[n][3]=a[j][3];
					}
				}
				else{
					stu k;
					k.lo=a[j][1];
					k.num=j;
					k.sml=max(a[j][2],a[j][3]);
					q1.push(k);
				}
			}
			if(a[j][2]>a[j][1]&&a[j][2]>a[j][3]){
				if(q2.size()+1>lk){
					if((q2.top().lo-q2.top().sml)<(a[j][2]-max(a[j][1],a[j][3]))){
						int num1=q2.top().num;
						q2.pop();
						n++;
						a[n][1]=a[num1][1];
						a[n][2]=0;
						a[n][3]=a[num1][3];
						stu k;k.lo=a[j][2];
						k.sml=max(a[j][1],a[j][3]);
						k.num=j;q2.push(k);
					}else{
						n++;
						a[n][1]=a[j][1];
						a[n][2]=0;
						a[n][3]=a[j][3];
					}
				}
				else{
					stu k;
					k.lo=a[j][2];
					k.num=j;
					k.sml=max(a[j][1],a[j][3]);
					q2.push(k);
				}
			}
			if(a[j][3]>a[j][1]&&a[j][3]>a[j][2]){
				if(q3.size()+1>lk){
					if((q3.top().lo-q3.top().sml)<(a[j][3]-max(a[j][2],a[j][1]))){
						int num1=q3.top().num;
						q3.pop();
						n++;
						a[n][1]=a[num1][1];
						a[n][2]=a[num1][2];
						a[n][3]=0;
						stu k;k.lo=a[j][3];
						k.sml=max(a[j][2],a[j][1]);
						k.num=j;q3.push(k);
					}else{
						n++;
						a[n][1]=a[j][1];
						a[n][2]=a[j][2];
						a[n][3]=0;
					}
				}
				else{
					stu k;k.lo=a[j][3];
					k.sml=max(a[j][2],a[j][1]);
					k.num=j;q3.push(k);
				}
			}
			
		}int ans=0;
		while(q1.size()!=0){
			stu l=q1.top();
			ans+=l.lo;
			q1.pop();
		}
		while(q2.size()!=0){
			stu l=q2.top();
			ans+=l.lo;
			q2.pop();
		}
		while(q3.size()!=0){
			stu l=q3.top();
			ans+=l.lo;
			q3.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}/*不管怎样得留下一点，
	至少证明我来过*/ 
