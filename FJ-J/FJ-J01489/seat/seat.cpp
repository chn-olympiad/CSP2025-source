#include<bits/stdc++.h>
using namespace std;
struct stu{
	int grade,num;
	static bool cmp(stu x,stu y){
		return x.grade>y.grade;
	}
}a[105];
int n,m,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].grade;
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,stu::cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			//cout<<i<<endl;
			ans1=(i+n-1)/n;
			if(ans1%2==1) ans2=i-(ans1-1)*n;
			else ans2=n+1-(i-(ans1-1)*n);
			break;
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
