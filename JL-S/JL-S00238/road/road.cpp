#include<fstream>
#include<iostream>
using namespace std;
long long n,m,k,alsum=-1;
long long u[1000000],v[1000000],w[1000000],c[10],a[10][10000],ok[10000],cok[10];

int findthat(long long step,long long now){
		if(alsum!=-1 and alsum<now){
			return now;
		}
		long long most=0,sum=-1,b;
		bool isok=true;
		for(int i_1=0;i_1<n;i_1++){
			if(ok[i_1]==0){
				isok=false;
				break;
			}
		}
		if(isok){
			if(alsum==-1 or alsum>now){
				alsum=now;
			}
			return now;
		}
		for(int i_1=0;i_1<m;i_1++){
			if((u[i_1]!=step&&v[i_1]!=step)){
				continue;
			}
			if((ok[u[i_1]]==1 and u[i_1]!=step)||(ok[v[i_1]]==1 and v[i_1]!=step)){
				continue;
			}
			if(u[i_1]!=step){
				b=u[i_1];
			}
			else{
				b=v[i_1];
			}
			if(ok[b]==1){
				continue;
			}
			ok[b]=1;
			most=findthat(b,w[i_1]+now);
			if((most<sum||sum==-1) and most>-1){
				sum=most;
			}
			ok[b]=0;
		}
		for(int i_1=0;i_1<k;i_1++){
			if(c[i_1]+a[i_1][step]<sum or cok[i_1]==1){
				for(int i_2=0;i_2<n;i_2++){
					if(cok[i_1]!=1){
						most=c[i_1]+a[i_1][step]+a[i_1][i_2];
					}
					else{
						most=a[i_1][step]+a[i_1][i_2];
					}
					if(i_2==step||most>sum||ok[i_2]==1){
						continue;
					}
					ok[i_2]=1;
					cok[i_1]=1;
					most=findthat(i_2,w[i_1]+most);
					if((most<sum||sum==-1) and most>-1){
						sum=most;
					}
					ok[i_2]=0;
					cok[i_1]=0;
				}
			}
		}
	return now+sum;
}
int main(){
	ifstream inFilm("road.in");
	ofstream outFilm("road.out");
	inFilm>>n>>m>>k;

	for(int i_1=0;i_1<n;i_1++){
		ok[i_1]=0;
	}
	for(int i_1=0;i_1<m;i_1++){
		inFilm>>u[i_1]>>v[i_1]>>w[i_1];
		u[i_1]-=1;
		v[i_1]-=1;
	}
	for(int i_1=0;i_1<k;i_1++){
		inFilm>>c[i_1];
		cok[i_1]=0;
		for(int i_2=0;i_2<n;i_2++){
			inFilm>>a[i_1][i_2];
		}
	}
	ok[0]=1;
	outFilm<<findthat(0,0);

	return 0;
}
