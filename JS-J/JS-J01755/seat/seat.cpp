#include <bits/stdc++.h>
using namespace std;

int n,m,score[105],ansn = 1,ansm = 1,cur;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++)cin>>score[i];
	cur = score[1];
	sort(score+1,score+n*m+1,cmp);
	for (int i = 1;i<=n*m;i++) {
        if (score[i] == cur) break;
        else{
            if ((ansn == n && (ansm & 1))||(ansn == 1 && (!(ansm & 1)))){
                ansm++;
            }else{
                if (ansm&1) ansn++;
                else ansn--;
            }

        }
	}
	cout<<ansm<<' '<<ansn;
    return 0;
}
