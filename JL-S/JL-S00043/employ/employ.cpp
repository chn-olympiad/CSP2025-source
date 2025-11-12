#include <bits/stdc++.h>
#define int long long
using namespace std;
struct word{
	int a,b,c;
}m[100010];
int t,n,ans,z,x,v;
int k[100010];
signed main (){
    freopen("club.in","read",stdin);
	freopen("club.out","write",stdout);
	cin>>t;
	for(int s=1;s<=t;s++){
		cin>>n;int l=0;
        if(n==2){
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			}
            k[1]=m[1].a+m[2].b;
            k[2]=m[1].a+m[2].c;
            k[3]=m[1].b+m[2].a;
            k[4]=m[1].b+m[2].c;
            k[5]=m[1].c+m[2].b;
            k[6]=m[1].c+m[2].a;
            sort(k+1,k+7);
            cout<<k[6];
        }
        if(n==4){
            int y=0;int p[3],o[3],h[3],u[3];
            cin>>p[1]>>p[2]>>p[3];
            cin>>o[1]>>o[2]>>o[3];
            cin>>h[1]>>h[2]>>h[3];
            cin>>u[1]>>u[2]>>u[3];
        for(int q=1;q<=3;q++){
            for(int w=1;w<=3;w++){
                for(int e=1;e<=3;e++){
                    for(int r=1;r<=3;r++){
                            if(q==1) z++;
                            if(q==2) x++;
                            if(q==3) v++;
                            if(w==1) z++;
                            if(w==2) x++;
                            if(w==3) v++;
                            if(e==1) z++;
                            if(e==2) x++;
                            if(e==3) v++;
                            if(r==1) z++;
                            if(r==2) x++;
                            if(r==3) v++;
                            if(z<=2&&x<=2&v<=2)
                                {k[++y]=p[q]+o[w]+u[r]+h[e];l++;
                            }
                    }
                }
            }
        }
    sort(k+1,k+1+l);
    cout<<k[l];
	}
	if(n==10){
        int y=0;int q1[3],q2[3],q3[4],q4[3],q5[5],q6[6],q7[4],q8[5],q9[4],q0[3];
        cin>>q1[1]>>q1[2]>>q1[3];
        cin>>q2[1]>>q2[2]>>q2[3];
        cin>>q3[1]>>q3[2]>>q3[3];
        cin>>q4[1]>>q4[2]>>q4[3];
        cin>>q5[1]>>q5[2]>>q5[3];
        cin>>q6[1]>>q6[2]>>q6[3];
        cin>>q7[1]>>q7[2]>>q7[3];
        cin>>q8[1]>>q8[2]>>q8[3];
        cin>>q9[1]>>q9[2]>>q9[3];
        cin>>q0[1]>>q0[2]>>q0[3];
        for(int i1=1;i1<=3;i1++){
            for(int i2=1;i2<=3;i2++){
            for(int i3=1;i3<=3;i3++){
            for(int i4=1;i4<=3;i4++){
            for(int i5=1;i5<=3;i5++){
            for(int i6=1;i6<=3;i6++){
            for(int i7=1;i7<=3;i7++){
            for(int i8=1;i8<=3;i8++){
            for(int i9=1;i9<=3;i9++){
            for(int i0=1;i0<=3;i0++){
            if(i1<=5&&i2<=5&&i3<=5&&i4<=5&&i5<=5&&i6<=5&&i7<=5&&i8<=5&&i9<=5&&i0<=5)
                k[++y]=q1[i1]+q2[i2]+q3[i3]+q4[i4]+q5[i5]+q6[i6]+q7[i7]+q8[i8]+q9[i9]+q0[i0];
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        sort(k+1,k+1+y);
        cout<<k[y];
        }
	}

	return 0;
	}
