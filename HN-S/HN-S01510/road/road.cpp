#include<bits/stdc++.h>
using namespace std;
struct road{
	int w;
	int v;
	int u;
};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,num=0;
	
	cin>>n>>m>>k;
	road map[m+n*k];
	int c[k];
	bool f[m+k];
	long long s[m+n*k],ans;
	for(int i=0;i<m;i++)
	{
		cin>>map[i].u>>map[i].v>>map[i].w;
		s[i]=map[i].w*10000000+i;
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];f[i+n]=0;
		for(int j=0;j<n;j++){
			cin>>map[m+i*n+j].w;
			s[m+i*n+j]=map[m+i*n+j].w*10000000+m+i*n+j;
			map[m+i*n+j].u=n+i+1;
			map[m+i*n+j].v=j+1;
			f[j]=0;
		}
	}/*for(int i=0;i<m+n*k;i++){
		cout<<map[i].u<<" ";//cout<<map[s[i]%10000000].u<<" "<<map[s[i]%10000000].v<<" "<<endl;
	}*/
	sort(s,s+(m+n*k));
	
	int p=0,o=0;
	while(num<n+k-1){
		//cout<<s[p]%10000000<<" ";
		if(!(f[map[s[p]%10000000].u]&&f[map[s[p]%10000000].v]))
		{
			ans+=s[p]/10000000;
			if(!f[map[s[p]%10000000].u]){f[map[s[p]%10000000].u]=1;o++;
			}
			if(!f[map[s[p]%10000000].v]){f[map[s[p]%10000000].v]=1;o++;
			}	
			num++;
			//cout<<num<<endl<<o<<endl;
		}
		else{
			if(num<o-1){
				num++;
				//cout<<num;
			}
		}
		p++;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
