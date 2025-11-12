#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,hkck=0,mpvlen;
vector<pair<int,int>> v[20];
vector<int> mpv[20];
map<int,int> mp[20];
struct edge{
	int data;
	map<int ,bool> st;
}a[500005];
void erjin(edge x){
	int k=x.data,i=0;
	while(k>0){
		if(k&1){
			x.st[i]=true;
		}
		k/=2;
		i++;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	edge k;
	scanf("%d%d",&n,&k.data);
	erjin(k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].data);
		if(a[i].data==0){
			hkck++;
		}
		erjin(a[i]);	
	}
	if(k.data==0){
		cout<<hkck;
	}else{
		for(int i=0,len=k.st.size();i<len;i++){
			vector<int> tru;
			vector<int> fal;
			tru.clear();
			fal.clear();
			for(int j=0;j<n;j++){
				if(a[j].st[i]){
					tru.push_back(j);
				}else{
					fal.push_back(j);
				}
			}
			if(k.st[i]){
				int h=0,m=0;
				for(int j=0,jlen=tru.size();j<jlen;j++){
					if(mp[i][h]==0){
						mpv[i].push_back(h);
					}
					if(mp[i][tru[j]]==0){
						mpv[i].push_back(tru[j]);
					}
					mp[i][h]++;
					mp[i][tru[j]]++;
					v[i].push_back({h,tru[j]});
					h=tru[j]+1;
					m=tru[j]-1;
					if(j>0){
						v[i].push_back({tru[j-1],m});
						if(mp[i][m]==0){
							mpv[i].push_back(m);
						}
						if(mp[i][tru[j-1]]==0){
							mpv[i].push_back(tru[j-1]);
						}
						mp[i][tru[j-1]]++;
						mp[i][m]++;
					}
				}
			}else{
				for(int j=0,jlen=tru.size()-1;j<jlen;j++){
					v[i].push_back({tru[j],tru[j+1]});
					if(mp[i][tru[j]]==0){
						mpv[i].push_back(tru[j]);
					}
					if(mp[i][tru[j+1]]==0){
						mpv[i].push_back(tru[j+1]);
					}
					mp[i][tru[j]]++;
					mp[i][tru[j+1]]++;
				}
			}
			int vlen=mpv[i].size();
			mpvlen=max(mpvlen,vlen);
		}
		for(int i=0;i<mpvlen;i++){
			int d=mpv[0][i];
			bool flag=true;
			for(int j=1,len=k.st.size();j<len;j++){
				bool fla=mp[j][d];
				if(fla==false){
					flag=false;
					break;
				}
			}
			if(flag){
				cnt++;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
