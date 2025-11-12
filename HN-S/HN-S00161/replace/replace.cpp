#include<bits/stdc++.h>
using namespace std;
int n,q,qs=0,hs=0,ol=0,op=0,ioi=0,oi=0,uz=0;
struct one{
	string s1,s2,s3,s4;
	int q,h;
}a[200005];
string t1,t2,tt1,tt2;
struct two{
	string s1,s2;
};
vector<two> v[200005];
map<string,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	ol=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].q=a[i].h=0;
		for(int j=0;j<min(a[i].s1.size(),a[i].s2.size());j++){
			if(a[i].s1[j]==a[i].s2[j]){
				a[i].q++;
			}
			else{
				break;
			}
		}
		for(int j=a[i].s1.size()-1,k=a[i].s2.size()-1;j>=0&&k>=0;j--,k--){
			if(a[i].s1[j]==a[i].s2[k]){
				a[i].h++;
			}
			else{
				break;
			}
		}
		a[i].s3=a[i].s4="";
		t1=t2="";
		for(int j=a[i].q;j<a[i].s1.size()-a[i].h;j++){
			a[i].s3+=a[i].s1[j];
		}
		for(int j=a[i].q;j<a[i].s2.size()-a[i].h;j++){
			a[i].s4+=a[i].s2[j];
		}
		for(int j=a[i].q-1;j>=0;j--){
			t1+=a[i].s1[j];
		}
		for(int j=a[i].s1.size()-a[i].h;j<a[i].s1.size();j++){
			t2+=a[i].s1[j];
		}
		if(uz==0) for(int j=0;j<a[i].s1.size();j++){
			if(a[i].s1[j]!='a'&&a[i].s1[j]!='b'&&a[i].s2[j]!='a'&&a[i].s2[j]!='b'){
				uz=1;
				break; 
			} 
		} 
		if(mp[(string)(a[i].s3+">"+a[i].s4)]==0){
			ol++;
			mp[(string)(a[i].s3+">"+a[i].s4)]=ol;
			v[ol].push_back({t1,t2});
		}
		else{
			v[mp[(string)(a[i].s3+">"+a[i].s4)]].push_back({t1,t2});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
		}
		else{
			qs=hs=0;
			for(int j=0;j<t1.size();j++){
				if(t1[j]==t2[j]){
					qs++;
				}
				else{
					break;
				}
			}
			for(int j=t1.size()-1;j>=0;j--){
				if(t1[j]==t2[j]){
					hs++;
				}
				else{
					break;
				}
			}
			tt1=tt2="";
			for(int j=qs;j<t1.size()-hs;j++){
				tt1+=t1[j];
				tt2+=t2[j];
			}
			op=0;
			if(q==1||uz==1){
				ioi=mp[(string)(tt1+">"+tt2)];
				for(int j=0;j<v[ioi].size();j++){
					oi=0;
					for(int k=0,k2=qs-1;k<v[ioi][j].s1.size();k++,k2--){
						if(k2<=-1||v[ioi][j].s1[k]!=t1[k2]){
							oi=1;
							break;
						}
					}
					if(oi==0) for(int k=0,k2=t1.size()-hs;k<v[ioi][j].s2.size();k++,k2++){
						if(k2>=t1.size()||v[ioi][j].s2[k]!=t1[k2]){
							oi=1;
							break;
						}
					}
					if(oi==0){
						op++;
					}
				}
			}
			else{
				ioi=mp[(string)(tt1+">"+tt2)];
				for(int j=0;j<v[ioi].size();j++){
					if(v[ioi][j].s1.size()<=qs&&v[ioi][j].s2.size()<=hs){
						op++;
					}
				}
			}
			cout<<op<<endl; 
		}
	}
	return 0;
}
