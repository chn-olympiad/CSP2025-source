];
struct node{
	int num;
	int w;
	bool friend operator<(node A,node B){
		return A.w > B.w;
	} 
};
node a1[N],a2[N],a3[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans = 0;
		int ren1=0,ren2=0,ren3=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			a1[j].num = 0;a1[j].w=0;
			a2[j].num = 0;a2[j].w=0;
			a3[j].num = 0;a3[j].w=0;
			b[j]=0;
		}
		for(int j=1;j<=n;j++){
			a1[j].num = j;
			a2[j].num = j;
			a3[j].num = j;
			cin>>a1[j].w>>a2[j].w>>a3[j].w;
		}
		sort(a1+1,a1+n+1);sort(a2+1,a2+n+1);sort(a3+1,a3+n+1);
		int ren = 0;
		int j1=1,j2=1,j3=1;
		while(ren<n){
			 if(a1[j1].w>=a2[j2].w && a1[j1].w>=a3[j3].w){
			 	if(b[a1[j1].num]==0 && ren1<(n/2)){
			 		ren++;ren1++;j1++;b[a1[j1].num]=1;ans+=a1[j1].w;continue;
				}
				if(a2[j2].w>=a3[j3].w){
					if(b[a2[j2].num]==0 && ren2<(n/2)){
						ren++;ren2++;j2++;b[a2[j2].num]=1;ans+=a2[j2].w;continue;
					}
					if(b[a3[j3].num]==0 && ren3<(n/2)){
						ren++;ren3++;j3++;b[a3[j3].num]=1;ans+=a3[j3].w;continue;
					}
					j1++;j2++;j3++;continue;
				}
				else{
					if(b[a3[j3].num]==0 && ren3<(n/2)){
						ren++;ren3++;j3++;b[a3[j3].num]=1;ans+=a3[j3].w;continue;
					}
					if(b[a2[j2].num]==0 && ren2<(n/2)){
						ren++;ren2++;j2++;b[a2[j2].num]=1;ans+=a2[j2].w;continue;
					}
					j1++;j2++;j3++;continue;
				}
			 }
			 else if(a2[j2].w>=a1[j1].w && a2[j2].w>=a3[j3].w){
			 	if(b[a2[j2].num]==0 && ren2<(n/2)){
						ren++;ren2++;j2++;b[a2[j2].num]=1;ans+=a2[j2].w;continue;
					}
				if(a1[j1].w>=a3[j3].w){
					if(b[a1[j1].num]==0 && ren1<(n/2)){
						ren++;ren1++;j1++;b[a1[j1].num]=1;ans+=a1[j1].w;continue;
					}
					if(b[a3[j3].num]==0 && ren3<(n/2)){
						ren++;ren3++;j3++;b[a3[j3].num]=1;ans+=a3[j3].w;continue;
					}
					j1++;j2++;j3++;continue;
				}
				else{
					if(b[a3[j3].num]==0 && ren3<(n/2)){
						ren++;ren3++;j3++;b[a3[j3].num]=1;ans+=a3[j3].w;continue;
					}
					if(b[a1[j1].num]==0 && ren1<(n/2)){
						ren++;ren1++;j1++;b[a1[j1].num]=1;ans+=a1[j1].w;continue;
					}
					j1++;j2++;j3++;continue;
				}
			 }
			 else{
			 	if(b[a3[j3].num]==0 && ren3<(n/2)){
					ren++;ren3++;j3++;b[a3[j3].num]=1;ans+=a3[j3].w;continue;
				}
				if(a1[j1].w>=a2[j2].w){
					if(b[a1[j1].num]==0 && ren1<(n/2)){
						ren++;ren1++;j1++;b[a1[j1].num]=1;ans+=a1[j1].w;continue;
					}
					if(b[a2[j2].num]==0 && ren2<(n/2)){
						ren++;ren2++;j2++;b[a2[j2].num]=1;ans+=a2[j2].w;continue;
					}
					j1++;j2++;j3++;continue;
				}
				else{
					if(b[a2[j2].num]==0 && ren2<(n/2)){
						ren++;ren2++;j2++;b[a2[j2].num]=1;ans+=a2[j2].w;continue;
					}
					if(b[a1[j1].num]==0 && ren1<(n/2)){
						ren++;ren1++;j1++;b[a1[j1].num]=1;ans+=a1[j1].w;continue;
					}
					j1++;j2++;j3++;continue;
				}
			 }
		}
		cout<<ans<<'\n';
	}
	return 0;
}
