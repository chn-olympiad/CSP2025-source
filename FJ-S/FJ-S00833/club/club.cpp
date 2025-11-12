#include<bits/stdc++.h>
using namespace std;

const int Max=1e5+10;
int t,n,FULL,sum;

struct stt{
	int v,i;
};

struct st{
	stt a[4];
}s[Max];



bool cmp(stt a,stt b){
	return a.v>b.v;
}



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt[4]={0};
		priority_queue<int> q[4];
		sum=0;
		FULL=n/2;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>s[i].a[0].v>>s[i].a[1].v>>s[i].a[2].v;
			s[i].a[0].i=0;
			s[i].a[1].i=1;
			s[i].a[2].i=2;
			sort(s[i].a,s[i].a+3,cmp);
		}
		for(int i=0;i<n;i++){
			int t=s[i].a[0].i;
			cnt[t]++;
			if(cnt[t]>FULL){
				cnt[t]--;
				sum+=s[i].a[0].v;
//				cout<<q[t].top()<<":"<<s[i].a[0].v<<"-"<<s[i].a[1].v<<endl;
				sum-=min(-q[t].top(),s[i].a[0].v-s[i].a[1].v);
				q[t].pop();
				q[t].push(-max(-q[t].top(),s[i].a[0].v-s[i].a[1].v));
//				cout<<-q[t].top()<<endl;
			}else{
				sum+=s[i].a[0].v;
				q[t].push(-(s[i].a[0].v-s[i].a[1].v));
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
