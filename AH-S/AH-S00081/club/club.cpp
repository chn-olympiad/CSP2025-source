#include <bits/stdc++.h>
using namespace std;
struct member{
    int score;
    int num;
};
bool cmp(member x,member y){
    return x.score>y.score;
}
int n,limit;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
        int ans=0;
        cin>>n;
        limit=n/2;
        struct member a[n+1][4];
        int clubs[4]={0},clubn[4][n/2+1];
        for(int j=1;j<=n;j++){
            cin>>a[j][1].score>>a[j][2].score>>a[j][3].score;
            a[j][1].num=1;
            a[j][2].num=2;
            a[j][3].num=3;
            sort(a[j]+1,a[j]+4,cmp);
            if(clubs[a[j][1].num]==limit){
                int pos=0,lin=0;
                for(int k=1;k<=limit;k++){
                    if(a[clubn[a[j][1].num][k]][2].score+a[j][1].score-a[clubn[a[j][1].num][k]][1].score-a[j][2].score>lin){
                        pos=k;
                        lin=a[clubn[a[j][1].num][k]][2].score+a[j][1].score-a[clubn[a[j][1].num][k]][1].score-a[j][2].score;
                    }
                }
                if(lin==0){
                    clubs[a[j][2].num]++;
                    clubn[a[j][2].num][clubs[a[j][2].num]]=a[j][2].num;
                    ans+=a[j][2].score;
                }else{
                    int lin1=clubn[a[j][1].num][pos];
                    clubn[a[j][1].num][pos]=j;
                    clubs[a[lin1][2].num]++;
                    clubn[a[lin1][2].num][clubs[a[lin1][2].num]]=lin1;
                    ans=ans-a[lin1][1].score+a[lin1][2].score+a[j][1].score;
                }
            }else{
                clubs[a[j][1].num]++;
                clubn[a[j][1].num][clubs[a[j][1].num]]=j;
                ans+=a[j][1].score;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
