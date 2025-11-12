#include <bits/stdc++.h>
using namespace std;
long long n,a[100005][3],chz[5];
struct node{
	int num,p,k;
}nax[100005];
bool cmp(node a,node b){
    return a.num>b.num;
}
long long df;
int main(){//long long
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>df;
    for(int g=0;g<df;g++){
    cin>>n;
    long long cnt=0;
    for(long long  i=0;i<n;i++){
		long long maxx=0;
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(maxx<=a[i][j])
				nax[i].k=j;
			maxx=max(maxx,a[i][j]);

		}nax[i].num=maxx;nax[i].p=i;
	}
	sort(nax,nax+n,cmp);
	for(int i=0;i<n;i++){
		if(chz[nax[i].k]<=n/2){
				cnt+=nax[i].num;
				chz[nax[i].k]++;
		}
		else{
			a[nax[i].p][nax[i].k]=-1;;
			nax[i].num=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2])nax[i].k=0;
			else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2])nax[i].k=1;
			else nax[i].k=2;
			if(chz[nax[i].k]<=n/2){
                    cnt+=nax[i].num;chz[nax[i].k]++;}
			else{
				a[nax[i].p][nax[i].k]=-1;

				nax[i].num=max(a[i][0],max(a[i][1],a[i][2]));
				if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2])nax[i].k=0;
				else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2])nax[i].k=1;
				else nax[i].k=2;
				if(chz[nax[i].k]<=n/2){cnt+=nax[i].num;chz[nax[i].k]++;}
			}

		}
	}
	cout<<cnt<<endl;

}
	fclose(stdin);
	fclose(stdout);
}

