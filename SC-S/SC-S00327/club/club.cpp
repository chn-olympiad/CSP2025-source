#include<bits/stdc++.h>
using namespace std;
int t,n;
queue<int>r1;
queue<int>r2;
queue<int>r3;
struct stu{
	int yi,er,san;
	int maxn;
}a[100005];
bool cmp(stu x,stu y){
	return x.maxn>y.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int min1=0x3f3f3f3f,min2=0x3f3f3f3f,min3=0x3f3f3f3f;
		long long sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].yi>>a[i].er>>a[i].san;
			a[i].maxn=max(a[i].yi,max(a[i].er,a[i].san));
		}sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].yi==a[i].maxn){
				c:
				if(r1.size()<n/2){
					r1.push(a[i].yi);
					min1=min(a[i].yi,min1);
				}
				else if(a[i].yi>min1){
					sum-=min1+=a[i].yi;
				}else if(a[i].er>a[i].san)goto a;
				else goto b;
			}else if(a[i].er==a[i].maxn){
				a:
				if(r2.size()<n/2){
					r2.push(a[i].er);
					min2=min(a[i].er,min2);
				}
				else if(a[i].er>min2){
					sum-=min2+=a[i].er;
				}else if(a[i].yi>a[i].san)goto c;
				else goto b;
			}else{
				b:
				if(r3.size()<n/2){
					r3.push(a[i].san);
					min3=min(a[i].san,min3);
				}
				else if(a[i].san>min3){
					sum-=min3+=a[i].san;
				}else if(a[i].yi>a[i].er)goto c;
				else goto a;
			}
		}while(!r1.empty()){
			sum+=r1.front();
			r1.pop();
		}while(!r2.empty()){
			sum+=r2.front();
			r2.pop();
		}while(!r3.empty()){
			sum+=r3.front();
			r3.pop();
		}printf("%lld\n",sum);
	}
	return 0;
}