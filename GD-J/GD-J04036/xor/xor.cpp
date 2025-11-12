#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500050],xor_ans,point_num=1,ans;
bool v[500050];
struct point{
	int L,R;
}t[500050];
bool cmp(point x,point y){
	return (x.R-x.L)<(y.R-y.L);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		xor_ans=a[i];
		if(xor_ans==k)
			t[point_num].L=i,t[point_num].R=i,++point_num;	
		else
			for(int j=i+1;j<=n;++j){
				xor_ans=(xor_ans xor a[j]);
				if(xor_ans==k){
					t[point_num].L=i,t[point_num].R=j,++point_num;
					break;
				}
			}
	}
	sort(t+1,t+point_num,cmp);
	for(int i=1;i<point_num;++i){
		for(int j=t[i].L;j<=t[i].R;++j){
			if(v[j])goto fail;
		}
		v[t[i].L]=true,v[t[i].R]=true;
		++ans; 
		fail:	;
	}
	cout<<ans<<endl;
	return 0;
}
