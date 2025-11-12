#include<bits/stdc++.h>
using namespace std;
int n,q;
long long cha[200000];
string v1[200000],v2[200000];
long long y[200000];
long long qe[200000];
long long cont=0;
long long hx[26];
int KMP(string c1,string c2,int num){
	int tr=v1[num].size();
	long long tic=0;
	for(int i=0;i<c1.size();i++){
		tic=hx[int(c1[i]-'a')]+tic;
	}
	int ans=0;
	for(int i=0;i<c2.size();i++){
		ans=hx[int(c2[i]-'a')]+ans;
	}
	return 	tic-ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=0;i<26;i++) hx[i]=i*i*i+i*i*114+i*1145;
	hx[0]=54321;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>v1[i]>>v2[i];
		y[i]=0;
		for(int j=0;j<v1[i].size();j++){
			int zz=int(v1[i][j]-'a');
			y[i]=y[i]+hx[zz];
		}
		qe[i]=0;
		for(int j=0;j<v2[i].size();j++){
			qe[i]=qe[i]+hx[int(v2[i][j]-'a')];
		}
		cha[i]=y[i]-qe[i];
	//	cout<<y[i]<<' '<<qe[i]<<endl;
	//	cout<<cha[i]<<endl;
	} 
	string c1,c2;
	sort(cha,cha+n);
	long long tong[n],ctong[n],vs=1;
	tong[0]=cha[0];
	ctong[0]=1;
	for(int i=1;i<n;i++){
		if(tong[vs-1]==cha[i]) ctong[vs-1]++;
		else{
			tong[vs]=cha[i];
			ctong[vs]=1;
			vs++;
		}
	}
	for(int i=0;i<q;i++){
		cin>>c1>>c2;	
		int rs=KMP(c1,c2,i);
	//	cout<<rs<<"  ";
		int l=0,r=vs-1;
		int mids=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(tong[mid]==rs){
				cont=ctong[mid];
				break;
			}
			else if (tong[mid]<rs){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		
		cout<<cont<<endl;
		cont=0;
	}
	return 0;
} 
