#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
int n,m;
int const D=200;
int a[D];
int x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int p=1,q=1,i=1;
	int dis=0;
	while(1){
		if(a[i]==x){
			cout<<q<<' '<<p;
			return 0;
		}
		i++;
		if(p==n&&dis==0){
			q++;dis=1;
		}
		else if(p==1&&dis==1){
			q++;dis=0;
		}
		else{
			if(dis==0){
				p++;
			}
			else if(dis==1){
				p--;
			}
		}
	}
	return 0;
}
