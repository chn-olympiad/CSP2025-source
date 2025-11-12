#include<bits/stdc++.h>
#define endl '\n'
using namespace std;//rp++
struct stu{
	int pts;
	int r,c;
	int id,num;
	bool isr=false;
}a[106];
int n,m;
bool cmp(stu x,stu y){
	return x.pts>y.pts;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].pts;
		if(i==1){
			a[i].isr=true;
		}
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int R=1,C=1;//R是行 C是列！！！！！！！别搞混了
//	for(int i=1;i<=n*m;i++) cout<<a[i].pts<<" "<<a[i].num<<" "<<a[i].isr<<endl;
	bool isup=false,isdown=true;
	for(int i=1;i<=n*m;i++){
		a[i].r=R;
		a[i].c=C;
		a[i].num=i;
		if(isdown) {
			if(R==n){
				C++;
				R=n;
				isup=true;
				isdown=false;
			}
			else R++;
		}
		else if(isup){
			if(R==1){
				C++;
				R=1;
				isup=false;
				isdown=true;
			}
			else R--;
		}
		if(a[i].isr) cout<<a[i].c<<" "<<a[i].r;//C和R要反着输出！！
	}//然后是N行M列！！！！
	return 0;
}