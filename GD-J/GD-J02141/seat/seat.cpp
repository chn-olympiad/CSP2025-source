#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,Rs,h=1,l=1,t=1;
	int score[105];
	int mp[11][11];
	cin>>n>>m;
	cin>>Rs;
	score[1]=Rs;
	int size=n*m;
	for(int i=2;i<=size;++i){
		cin>>score[i];
	}
	sort(score+1,score+1+size,cmp);
	while(h<=n){
		if(h%2==1){
			l=1;
			while(l<=m){
				if(Rs==score[t]){
					cout<<h<<" "<<l;
					return 0;
				}
				mp[l][h]=score[t];
				l++,t++;
			}
		}
		if(h%2==0){
			l=m;
			while(l>=1){
				if(Rs==score[t]){
					cout<<h<<" "<<l;
					return 0;
				}
				mp[l][h]=score[t];
				l--,t++;
			}
		} 
		h++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
