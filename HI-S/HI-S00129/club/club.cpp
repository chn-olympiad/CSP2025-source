#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct Ppl{
	int a,b,c;
};
struct Sac{
	int nt,note;
};
int n,t; 
bool SacCmp(Sac saca,Sac sacb){
	return (saca.note<sacb.note);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		long long ans=0;
		Ppl stu[N];
		vector<Sac>na;
		vector<Sac>eu;
		vector<Sac>as;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
			if (stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c){
				na.push_back({i,stu[i].a-max(stu[i].b,stu[i].c)});
				ans+=stu[i].a;
				//cout << 1 << ' ' << stu[i].a-max(stu[i].b,stu[i].c) << endl;
			}else if (stu[i].b>=stu[i].a&&stu[i].b>=stu[i].c){
				eu.push_back({i,stu[i].b-max(stu[i].a,stu[i].c)});
				ans+=stu[i].b;
				//cout << 2 << ' ' << stu[i].b-max(stu[i].a,stu[i].c) << endl;
			}else{
				as.push_back({i,stu[i].c-max(stu[i].a,stu[i].b)});
				ans+=stu[i].c;
				//cout << 3 << ' ' << stu[i].c-max(stu[i].b,stu[i].a) << endl;
			}
		}
			if (na.size()>(n/2)){
				sort(na.begin(),na.end(),SacCmp);
				int need=na.size()-n/2;
				for(int i=0;i<need;i++){
					if (stu[na[i].nt].b>=stu[na[i].nt].c){
						eu.push_back({na[i].nt,stu[na[i].nt].b-stu[na[i].nt].c});
						ans=ans-stu[na[i].nt].a+stu[na[i].nt].b;
					}else{
						as.push_back({na[i].nt,stu[na[i].nt].c-stu[na[i].nt].b});
						ans=ans-stu[na[i].nt].a+stu[na[i].nt].c;
					}stu[na[i].nt].a=0; na[i]={0,0};
					//cout <<ans << ' ';
				}
			}if (eu.size()>(n/2)){
				sort(eu.begin(),eu.end(),SacCmp);
				int need=eu.size()-n/2;
				for(int i=0;i<need;i++){
					//cout << eu[i].nt << ' ' << eu[i].note << endl;
					if (stu[eu[i].nt].c>=stu[eu[i].nt].a){
						as.push_back({eu[i].nt,stu[eu[i].nt].c-stu[eu[i].nt].a});
						ans=ans-stu[eu[i].nt].b+stu[eu[i].nt].c;
					}else{
						na.push_back({eu[i].nt,stu[eu[i].nt].a-stu[eu[i].nt].c});
						ans=ans-stu[eu[i].nt].b+stu[eu[i].nt].a;
					}stu[eu[i].nt].b=0; eu[i]={0,0};
					//cout <<ans << ' ';
				}
			}if (as.size()>(n/2)){
				sort(as.begin(),as.end(),SacCmp);
				int need=as.size()-n/2;
				for(int i=0;i<need;i++){
					if (stu[as[i].nt].a>=stu[as[i].nt].b){
						na.push_back({as[i].nt,stu[as[i].nt].a-stu[as[i].nt].b});
						ans=ans-stu[as[i].nt].c+stu[as[i].nt].a;
					}else{
						eu.push_back({as[i].nt,stu[as[i].nt].b-stu[as[i].nt].a});
						ans=ans-stu[as[i].nt].c+stu[as[i].nt].b;
					}stu[as[i].nt].c=0; as[i]={0,0};
					//cout <<ans << ' ';
				}
			}
		printf("%lld\n",ans);
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
