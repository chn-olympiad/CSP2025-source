#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	long long A,B,C;
}Member[N];
long long T,Num,Sum;
bool Cmp(Node X,Node Y){return X.A>Y.A;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		Sum=0;
		cin>>Num;
		for(int i=1;i<=Num;i++){
			cin>>Member[i].A>>Member[i].B>>Member[i].C;
		}
		sort(Member+1,Member+Num+1,Cmp);
		cout<<Member[1].A+Member[2].A<<endl;
		for(int i=1;i<=Num;i++){
			Member[i].A=0;
			Member[i].B=0;
			Member[i].C=0;
		}
	}
	return 0;
}
