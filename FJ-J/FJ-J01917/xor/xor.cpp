#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],cnt[2];
vector<pair<int,int> >vec;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool flag=true,f=false;
	int tmp=0,sta=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
//			printf(" Start:---> a[i]=0:sta:%d tmp:%d\n",sta,tmp);
			cnt[0]++;
			vec.push_back(make_pair(sta,tmp));
			f=false;
			tmp=0,sta=0;
//			printf(" End:---> a[i]=0:sta:%d tmp:%d\n",sta,tmp);
		}
		else if(a[i]==1){
//			printf(" Start:---> a[i]=1:sta:%d tmp:%d\n",sta,tmp);
			if(f){
				tmp=tmp+1;
//				printf("Now,tmp is the num %d\n",tmp);
			}else{
				sta=i;
				f=true;
				tmp++;
//				printf("Oh,tmp is the num %d\n",tmp);
			}
			cnt[1]++;
//			printf(" End:---> a[i]=1:sta:%d tmp:%d\n",sta,tmp);
		}else{
//			printf(" Start:---> a[i]=etc:sta:%d tmp:%d\n",sta,tmp);
			vec.push_back(make_pair(sta,tmp));
			f=false;
			tmp=0,sta=0;
			flag=false;
//			printf(" End:---> a[i]=etc:sta:%d tmp:%d\n",sta,tmp);
		}
	}
	if(tmp!=0  && sta!=0) vec.push_back(make_pair(sta,tmp));
	if(flag){
		if(k==1){
			printf("%d",cnt[1]);
		}else{
			int ans=cnt[0];
			for(int i=0;i<vec.size();i++){
				ans=ans+(vec[i].second)/2;
			}
			printf("%d",ans);
		}
	}else{
		putchar('0');
	}
	return 0;
}
