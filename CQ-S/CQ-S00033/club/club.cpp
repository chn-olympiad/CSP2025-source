#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
};
int t;
int n;
const int N=1e5+10;
node x[N];
vector<int> va;
vector<int> vb;
vector<int> vc;
int h;
int zx;
int abi;
int abj;
int aci;
int acj; 
int i_mi;
int j_mi;
int i_ma;

int j_ma;
void debug(){
	cout<<"\n A:";
	for(int i=0;i<va.size();i++){
		cout<<va[i]<<' ';
	}
	cout<<"\n B:";
	for(int i=0;i<vb.size();i++){
		cout<<vb[i]<<' ';
	}
	cout<<"\n C:";
	for(int i=0;i<vc.size();i++){
		cout<<vc[i]<<' ';
	}
	cout<<"\n===================";
}
int sl(int v,int fz){
	int ma=x[v].a;
	int mb=x[v].b;
	int mc=x[v].c;
	if(fz==1){
		if((ma-mb)<=(ma-mc)){
			zx= 2;
		}else{
			zx= 3;
		}
	}
	if(fz==2){
		if((mb-ma)<(mb-mc)){
			zx= 1;
		}else{
			zx= 3;
		}
	}
	if(fz==3){
		if((mc-ma)<(mc-mb)){
			zx= 1;
		}else{
			zx= 2;
		}
	}
}
bool cmpa(int i,int j){
	abi=x[i].a-x[i].b;
	abj=x[j].a-x[j].b;
	aci=x[i].a-x[i].c;
	acj=x[j].a-x[j].c; 
	i_mi=min(abi,aci);
	j_mi=min(abj,acj);
	int i_ma=max(abi,aci);
	int j_ma=max(abj,acj);
	if(i_mi==j_mi) return i_ma>j_ma;
	return i_mi>j_mi;
}
bool cmpb(int i,int j){
	abi=x[i].b-x[i].a;
	abj=x[j].b-x[j].a;
	aci=x[i].b-x[i].c;
	acj=x[j].b-x[j].c; 
	//debug();
	i_mi=min(abi,aci);
	j_mi=min(abj,acj);
	int i_ma=max(abi,aci);
	int j_ma=max(abj,acj);
	/*if(i_ma==j_ma) return i_mi>j_mi;
	return i_ma>j_ma;*/
	if(i_mi==j_mi) return i_ma>j_ma;
	return i_mi>j_mi;
}
bool cmpc(int i,int j){
	abi=x[i].c-x[i].b;
	abj=x[j].c-x[j].b;
	aci=x[i].c-x[i].a;
	acj=x[j].c-x[j].a; 
	i_mi=min(abi,aci);
	j_mi=min(abj,acj);
	int i_ma=max(abi,aci);
	int j_ma=max(abj,acj);
/*	cout<<"======================\n"; 
	cout<<i<<' '<<j<<'\n';
	cout<<abi<<' '<<abj<<' '<<aci<<' '<<acj;
	cout<<"======================\n"; */
	if(i_mi==j_mi) return i_ma>j_ma;
	return i_mi>j_mi;
}
bool ch(){
	return va.size()<=h&&vb.size()<=h&&vc.size()<=h;
}


int main(){
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		va.clear();
		vb.clear();
		vc.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a==max({x[i].a,x[i].b,x[i].c})){
				va.push_back(i);	
				
			} 
			else if(x[i].b==max({x[i].a,x[i].b,x[i].c})) {
				vb.push_back(i);
				
			}
			else if(x[i].c==max({x[i].a,x[i].b,x[i].c})) {
				vc.push_back(i);
			}
			//cout<<n<<'/'<<i<<"++++++++++++++\n";
		}
		h=n/2;
		//debug();
		while(!ch()){
			sort(va.begin(),va.end(),cmpa);
			sort(vb.begin(),vb.end(),cmpb);
			sort(vc.begin(),vc.end(),cmpc);
			if(va.size()>h){
				while(va.size()>h){
					int tmp=va[va.size()-1];
					va.pop_back();
					sl(tmp,1);
					if(zx==2){
						vb.push_back(tmp);
					}
					else {
						vc.push_back(tmp);
					}
				}
			}
			if(vb.size()>h){
				while(vb.size()>h){
					int tmp=vb[vb.size()-1];
					vb.pop_back();
					sl(tmp,2);
					if(zx==1){
						va.push_back(tmp);
					}
					else {
						vc.push_back(tmp);
					}
				}
			}
			if(vc.size()>h){
				while(vc.size()>h){
					int tmp=vc[vc.size()-1];
					vc.pop_back();
					sl(tmp,3);
					if(zx==1){
						va.push_back(tmp);
					}
					else {
						vb.push_back(tmp);
					}
				}
			}
			//debug();
		}
		unsigned long long sum=0;
		for(int i=0;i<va.size();i++){
			sum+=x[va[i]].a;
		}
		for(int i=0;i<vb.size();i++){
			sum+=x[vb[i]].b;
		}
		for(int i=0;i<vc.size();i++){
			sum+=x[vc[i]].c;
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}
/*


3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042

*/
