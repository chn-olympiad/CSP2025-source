#include<bits/stdc++.h>
using namespace std;
int n,m;
int score;
int a[107];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		if(i==1){
			scanf("%d",&score);
		}
		else{
			scanf("%d",&a[i-1]);
		}
	}
	sort(a+1,a+n,greater<int>());
	int man=0;
	bool flag=0;
	for(int i=1;i<n*m;i++){
		if(score>a[i]){
			man=i;
			flag=1;
			break;
		}
	}
	if(flag==0){
		man=n*m;
	}
	int past=0;
	int now=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			past=now;
			now=now+2*n-1;
		}
		else{
			past=now;
			now=now+1;
		}
		if(past<man&&now>man){
			int dis=man-past;
			int indis=now-man;
			if(dis<indis){
				printf("%d %d",i,dis+1);
				return 0;
			}
			else{
				printf("%d %d",i+1,indis+1);
				return 0;
			}
		}
		if(past==man){
			printf("%d 1",i);
			return 0;
		}
		if(now==man){
			printf("%d 1",i+1);
			return 0;
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
