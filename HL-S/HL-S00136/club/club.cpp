#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,sata[4],satb[4],satc[4],maxa[100010],maxb[100010],maxc[100010],a=0,b=0,c=0,ans1=0,ans2=0,mina,minb,minc,k=1,number;
	cin>>t;
	while(t--){
		cin>>n;
		number=n/2;
		for (int i=1;i<=n;i++){
			cin>>sata[i]>>satb[i]>>satc[i];
		}
		for (int i=1;i<=n;i++){
			ans1+=max(max(sata[i],satb[i]),max(satb[i],satc[i]));
			ans2+=max(max(sata[i],satb[i]),max(satb[i],satc[i]));
			if (max(max(sata[i],satb[i]),max(satb[i],satc[i]))==sata[i]){
				a++;
				maxa[a]=sata[i];
				for (int j=2;j<=a-1;j++){
					mina=min(maxa[k],maxa[j]);
					if (min(maxa[k],maxa[j])==maxa[j]){
						k=j;
					}
				}
				if (a>number){
					a--;
					ans1-=mina;
					ans1+=max(satb[k],satc[k]);
					ans2-=sata[i];
					ans2+=max(satb[i],satc[i]);
					if(max(satb[i],satc[i])==satb[i]){
						b++;
					}
					else c++;
					
				}
			}
			else if (max(max(sata[i],satb[i]),max(satb[i],satc[i]))==satb[i]){
				b++;
				maxb[b]=sata[i];
				for (int j=1;j<=b-1;j++){
					minb=min(maxb[j],maxb[j+1]);
					if (min(maxb[k],maxb[j])==maxb[j]){
						k=j;
					}
				}
				if (b>number){
					b--;
					ans1-=minb;
					ans1+=max(sata[k],satc[k]);
					ans2-=satb[i];
					ans2+=max(sata[i],satc[i]);
					if(max(sata[i],satc[i])==sata[i]){
						a++;
					}
					else c++;
					
				}
			}
			else if (max(max(sata[i],satb[i]),max(satb[i],satc[i]))==satc[i]){
				c++;
				maxc[c]=satc[i];
				for (int j=1;j<=c-1;j++){
					minc=min(maxc[j],maxc[j+1]);
					if (min(maxc[k],maxc[j])==maxc[j]){
						k=j;
					}
				}
				if (c>number){
					c--;
					ans1-=minc;
					ans1+=max(sata[k],satc[k]);
					ans2-=satc[i];
					ans2+=max(sata[i],satb[i]);
					if(max(sata[i],satb[i])==sata[i]){
						a++;
					}
					else b++;
					
				}
			}
		}
		cout<<max(ans1,ans2);
		a=0;b=0;c=0;ans1=0,ans2=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
