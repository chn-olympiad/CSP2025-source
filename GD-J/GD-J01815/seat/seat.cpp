#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int maxn=10+10;
int score[100*100];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int R=score[1],Rid;
	sort(score+1,score+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i]==R) {
			Rid=i;
			break;
		}
	}
	int h=ceil(Rid*1.0/n);
	int w=Rid%m;
	if(w==0) w=m;
	if(h%2==0) w=(n-w)+1;  
	cout<<h<<' '<<w<<endl;
	return 0;
}
