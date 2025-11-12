#include<bits/stdc++.h>
using namespace std;
int t,n,k;
struct node{
	int a,b,c,id;
}a[100009];
int aa=0,bb=0,cc=0;
bool vis[100009];
long long ans=0;
int sum[100009],idx=0;
bool cmp1(node x,node y){
	/*
    int xx=abs(x.a-x.b),xxx=abs(x.b-x.c),xxxx=abs(x.a-x.c);
    int yy=abs(y.a-y.b),yyy=abs(y.b-y.c),yyyy=abs(y.a-y.c);
    if(xx>=xxx&&xx>=xxxx) xx=0;
    else if(xxx>=xx&&xxx>=xxxx) xxx=0;
    else if(xxxx>=xxx&&xxxx>=xx) xxxx=0;
    if(yy>=yyy&&yy>=yyyy) yy=0;
    else if(yyy>=yy&&yyy>=yyyy) yyy=0;
    else if(yyyy>=yyy&&yyyy>=yy) yyyy=0;
    xx=max(xx,max(xxx,xxxx));
    yy=max(yy,max(yyy,yyyy));
    */
    int xx,yy;
    int aa=x.a,bb=x.b,cc=x.c;
    if(aa>=bb&&aa>=cc){
		xx=min(abs(aa-bb),abs(aa-cc));
	}
	if(bb>=aa&&bb>=cc){
		xx=min(abs(aa-bb),abs(bb-cc));
	}
	if(cc>=bb&&cc>=aa){
		xx=min(abs(cc-bb),abs(aa-cc));
	}
	aa=y.a,bb=y.b,cc=y.c;
    if(aa>=bb&&aa>=cc){
		yy=min(abs(aa-bb),abs(aa-cc));
	}
	if(bb>=aa&&bb>=cc){
		yy=min(abs(aa-bb),abs(bb-cc));
	}
	if(cc>=bb&&cc>=aa){
		yy=min(abs(cc-bb),abs(aa-cc));
	}
    return xx>yy;
}
bool cmp2(node x,node y){
	int xx,yy;
    int aa=x.a,bb=x.b,cc=x.c;
    if(aa<=bb&&aa<=cc){
		xx=min(abs(aa-bb),abs(aa-cc));
	}
	if(bb<=aa&&bb<=cc){
		xx=min(abs(aa-bb),abs(bb-cc));
	}
	if(cc<=bb&&cc<=aa){
		xx=min(abs(cc-bb),abs(aa-cc));
	}
	aa=y.a,bb=y.b,cc=y.c;
    if(aa<=bb&&aa<=cc){
		yy=min(abs(aa-bb),abs(aa-cc));
	}
	if(bb<=aa&&bb<=cc){
		yy=min(abs(aa-bb),abs(bb-cc));
	}
	if(cc<=bb&&cc<=aa){
		yy=min(abs(cc-bb),abs(aa-cc));
	}
    return xx>yy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
        ans=0;
        aa=bb=cc=0;
        memset(vis,0,sizeof(vis));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++){
            if(max(a[i].a,max(a[i].b,a[i].c))==a[i].a&&aa<n/2){
                aa++;
                ans+=a[i].a;
                vis[a[i].id]=1;
            }
            if(max(a[i].a,max(a[i].b,a[i].c))==a[i].b&&bb<n/2){
                bb++;
                ans+=a[i].b;
                vis[a[i].id]=1;
            }
            if(max(a[i].a,max(a[i].b,a[i].c))==a[i].c&&cc<n/2){
                cc++;
                ans+=a[i].c;
                vis[a[i].id]=1;
            }
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++){
            if(vis[a[i].id]) continue;
            if(aa==n/2){
                if(a[i].b==a[i].c) continue;
                if(a[i].b>a[i].c&&bb<n/2){
                    bb++;
                    vis[a[i].id]=1;
                    ans+=a[i].b;
                }else{
                    cc++;
                    vis[a[i].id]=1;
                    ans+=a[i].c;
                }
            }
            else if(bb==n/2){
                if(a[i].a==a[i].c) continue;
                if(a[i].a>a[i].c&&aa<n/2){
                    aa++;
                    vis[a[i].id]=1;
                    ans+=a[i].a;
                }else{
                    cc++;
                    vis[a[i].id]=1;
                    ans+=a[i].c;
                }
            }
            else if(cc==n/2){
                if(a[i].b==a[i].a) continue;
                if(a[i].b>a[i].a&&bb<n/2){
                    bb++;
                    vis[a[i].id]=1;
                    ans+=a[i].b;
                }else{
                    aa++;
                    vis[a[i].id]=1;
                    ans+=a[i].a;
                }
            }
        }
        for(int i=1;i<=n;i++){
			if(vis[a[i].id]) continue;
			if(aa!=n/2){
				ans+=a[i].a;
				aa++;
			}
			else if(bb!=n/2){
				ans+=a[i].b;
				bb++;
			}
			else if(cc!=n/2){
				ans+=a[i].c;
				cc++;
			}
		}
        sum[++idx]=ans;
	}
	for(int i=1;i<=idx;i++) cout<<sum[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}