#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>a[10001];
vector<long long> city;
long long city1[10001],n,m,k,x,y,z,dj[11],hf[11],gx[11],hf2[11],cf,ctf,cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		city1[i]=1; 
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		a[x].push_back({y,z}); 
		a[y].push_back({x,z}); 
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&hf[i]);
		for(int j=1;j<=n;j++){
			cin>>x;
			a[n+i].push_back({j,x}); 
			a[j].push_back({n+i,x});
		}
	}
	city1[1]=0;
	ctf=n-1;cf=1;
	city.push_back(1);
	while(ctf){
	//	if(ctf>=cf){
			pair<long long,long long> nowcango={0,10000000001};long long last=0;
			for(long  long j:city){
				for(pair<long long,long long> i:a[j]){
				//	cout<<j<<"->"<<i.first<<"?\n";
					if(i.first>m){
						if(dj[i.first-n]==0){
							if(i.second+hf[i.first-n]<nowcango.second){
								nowcango={i.first,i.second+hf[i.first-n]};
								last=j;
							}
						}
					}else{
					if(city1[i.first]){
						if(i.second<nowcango.second){
							nowcango=i;	last=j;//cout<<"yes!\n";
						}
					}
					}
				}
			}

			//cout<<last<<"->"<<nowcango.first<<" "<<nowcango.second<<endl;
			if(nowcango.first>n){
				hf2[nowcango.first-n]=nowcango.second;
				cnt+=nowcango.second;
				dj[nowcango.first-n]=1;
				city.push_back(nowcango.first);
				
			}else{
				if(last>n){
					gx[last-n]++;
				}
				city1[nowcango.first]=0;
				cnt+=nowcango.second;
				ctf-=1;cf+=1;
				city.push_back(nowcango.first);
			}
	}
	for(int i=1;i<=k;i++){
	//	cout<<gx[i];
		if(gx[i]==0)cnt-=hf2[i];
	}
	printf("%lld",cnt);
	return 0;
}




