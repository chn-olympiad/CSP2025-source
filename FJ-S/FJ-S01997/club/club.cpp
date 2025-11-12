#include<bits/stdc++.h>
using namespace std;
struct stu{
	int s1,s2,s3;
}a[100005],sl1[100005],sl2[100005],sl3[100005];
bool cmp1(stu xs,stu ys){
	return xs.s1>ys.s1;
}
bool cmp2(stu xs,stu ys){
	return xs.s2>ys.s2;
}
bool cmp3(stu xs,stu ys){
	return xs.s3>ys.s3;
}
int t,n,top1,top2,top3;
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			int fff=max(max(a[i].s1,a[i].s2),a[i].s3);
			if(fff==a[i].s1){
				sl1[++top1]=a[i];
			}
			else if(fff=a[i].s2){
				sl2[++top2]=a[i];
			}
			else{
				sl3[++top3]=a[i];
			}
		}
		sort(sl1+1,sl1+top1+1,cmp1);
		sort(sl2+1,sl2+top2+1,cmp2);
		sort(sl3+1,sl3+top3+1,cmp3);
		if(top1>n/2){
			while(top1>n/2){
				int ff=max(sl1[top1].s2,sl1[top1].s3);
				if(ff==sl1[top1].s2){
					sl2[++top2]=sl1[top1];
					top1--;
				}
				else{
					sl3[++top3]=sl1[top1];
					top1--;
				}
			}
			sort(sl2+1,sl2+top2+1,cmp2);
			sort(sl3+1,sl3+top3+1,cmp3);
		}
		else if(top2>n/2){
			while(top2>n/2){
				int ff=max(sl2[top2].s1,sl2[top2].s3);
				if(ff==sl2[top2].s1){
					sl1[++top1]=sl2[top2];
					top2--;
				}
				else{
					sl3[++top3]=sl2[top2];
					top2--;
				}
			}
			sort(sl1+1,sl1+top1+1,cmp1);
			sort(sl3+1,sl3+top3+1,cmp3);
		}
		else if(top3>n/2){
			while(top3>n/2){
				int ff=max(sl3[top3].s1,sl3[top3].s2);
				if(ff==sl3[top3].s1){
					sl1[++top1]=sl3[top3];
					top3--;
				}
				else{
					sl2[++top2]=sl3[top3];
					top3--;
				}
			}
			sort(sl1+1,sl1+top1+1,cmp1);
			sort(sl2+1,sl2+top2+1,cmp2);
		}
		for(int i=1;i<=top1;i++){
			sum+=sl1[i].s1;
		}
		for(int i=1;i<=top2;i++){
			sum+=sl2[i].s2;
		}
		for(int i=1;i<=top3;i++){
			sum+=sl3[i].s3;
		}
		cout<<sum<<'\n';
		top1=top2=top3=sum=0;
	}
	return 0;
}
