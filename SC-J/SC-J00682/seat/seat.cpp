#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a[114],x,y;
	cin>>n>>m;
	x=m*n;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	y=a[1];
	sort(a+1,a+x+1,f);//sort得了MVP，for就是躺赢狗 
	
	//让我看看 
	for(int i=1;i<=x;i++){
		if(y==a[i]){
			//登dua郎 
			y=i;
			break;
		}
	}
	int o=1;//你也有计（数器） ？ 
	//一个一个找 
	for(int i=1;i<=m;i++){
		if(i%2==1){
			//从头找 
			for(int j=1;j<=n;j++,o++){
				if(o==y){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			//从尾找 
			for(int j=n;j>=1;j--,o++){
				if(o==y){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	//没座
	cout<<-1<<" "<<-1;
	return 0;
}