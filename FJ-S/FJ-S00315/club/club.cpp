#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e5+10;
struct pe
{
	int f,s,t;
}a[MAXN];


int maxt(int x,int y,int z) {return max(x,max(y,z));}
int maxs(int x,int y,int z)
{
	if(maxt(x,y,z) == x) return max(y,z);
	else if(maxt(x,y,z) == y) return max(x,z);
	else return max(x,y);
}

int maxtid(int x,int y,int z)
{
	if(maxt(x,y,z) == x) return 0;
	else if(maxt(x,y,z) == y) return 1;
	else return 2;
}
int maxsid(int x,int y,int z)
{
	if(maxs(x,y,z) == x) return 0;
	else if(maxs(x,y,z) == y) return 1;
	else return 2;
}
int lw(int x)
{
	int res = 0;
	while(x)
	{
		res++;
		x /= 10;
	}
	return res;
}
int uw(double x)
{
	int res = 0;
	double test = 1;
	while(x < test)
	{
		res++;
		test /= 10;
	}
	return res;
}
int pt(int x)
{
	int res = 1;
	for(int i = 0;i < x;i++) res *= 10;
	return res;
}

int cnta[3] = {0};

/*
bool cmp1(pe x,pe y)
{
	return maxt(x.f,x.s,x.t) > maxt(y.f,y.s,y.t);
}

bool cmp2(pe x,pe y)
{
	if(maxtid(x.f,x.s,x.t) == maxtid(cnta[0],cnta[1],cnta[2]) && maxtid(y.f,y.s,y.t) == maxtid(cnta[0],cnta[1],cnta[2]))
	return maxs(x.f,x.s,x.t) > maxs(y.f,y.s,y.t);
	else if(maxtid(x.f,x.s,x.t) == maxtid(cnta[0],cnta[1],cnta[2])) return maxs(x.f,x.s,x.t) > maxt(y.f,y.s,y.t);
	else if(maxtid(x.f,x.s,x.t) == maxtid(cnta[0],cnta[1],cnta[2])) return maxt(x.f,x.s,x.t) > maxs(y.f,y.s,y.t);
	else return maxt(x.f,x.s,x.t) > maxt(y.f,y.s,y.t);
}


struct node
{
	int data,id;
	operator >(const node &x,const node &y)
	{
		return x.data > y.data;
	}
}
*/

priority_queue<double,vector<double>,greater<double> > q[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i = 0;i < n;i++) cin>>a[i].f>>a[i].s>>a[i].t;
		for(int i = n;i < n+5;i++) a[i].f = a[i].s = a[i].t = 0;
		for(int i = 0;i < 3;i++)
		while(!q[i].empty()) q[i].pop();
		
		
		cnta[0] = cnta[1] = cnta[2] = 0;
		int sum = 0;
		for(int i = 0;i < n;i++)
		{
			//cout<<i<<endl;
			int w = maxtid(a[i].f,a[i].s,a[i].t),tw = maxsid(a[i].f,a[i].s,a[i].t),wd = maxt(a[i].f,a[i].s,a[i].t),twd = maxs(a[i].f,a[i].s,a[i].t);
			if(cnta[w] < n/2) 
			{
				double r = wd-twd + 1.0*i/pt(lw(i));
				//cout<<w<<" "<<r<<endl;
				//cout<<i<<endl;
				//cout<<w<<" "<<tw<<" "<<wd<<" "<<twd<<endl;
				q[w].push(r);
				cnta[w]++;
				sum += wd;
			}
			else
			{	
				
				double rt = q[w].top();
				
				int t = int(rt);
				//cout<<uw(rt - t)<<" "<<(rt - t)<<endl;
				int rid = int((rt - t) * pt(uw(rt - t))+0.5);
				//cout<<(rt - t) * pt(uw(rt - t))<<" "<<pt(uw(rt - t))<<endl;
				///////
				int rw = maxtid(a[rid].f,a[rid].s,a[rid].t),rtw = maxsid(a[rid].f,a[rid].s,a[rid].t),rwd = maxt(a[rid].f,a[rid].s,a[rid].t),rtwd = maxs(a[rid].f,a[rid].s,a[rid].t);
				//cout<<2134<<endl;
				//cout<<((rt - t) * pt(uw(rt - t)))<<endl;
				//cout<<rw<<" "<<rtw<<" "<<rwd<<" "<<rtwd<<endl;
				if(wd + rtwd > rwd + twd)
				{
					//cout<<5464<<endl;
					double rn = wd-twd + 1.0*i/pt(lw(i));
					//cout<<rn<<endl;
					q[w].pop();
					sum -= rwd;
					q[w].push(rn);
					sum += wd;
					double rl = rtwd + 1.0*rid/pt(lw(rid));
					//cout<<rn<<endl;
					q[rtw].push(rl);
					cnta[rtw]++;
					sum += rtwd;
					
				}
				else
				{
					//cout<<1234<<endl;
					double r = twd + 1.0*i/pt(lw(i));
					//cout<<r<<endl;
					q[tw].push(r);
					cnta[tw]++;
					sum += twd;
				}
			}
			
		}
		cout<<sum<<endl;
		
		/*
		//ผูมห 
		sort(a,a+n,cmp1);
		
		//for(int i = 0;i < n;i++) printf("%d %d %d\n",a[i].f,a[i].s,a[i].t);
		
		int sum = 0,k = 0;
		while(cnta[maxtid(cnta[0],cnta[1],cnta[2])] < n/2 && k < n)
		{
			sum += maxt(a[k].f,a[k].s,a[k].t);
			cnta[maxtid(a[k].f,a[k].s,a[k].t)]++;
			k++;
		}
		cout<<sum<<endl;
		if(k == n)
		{
			cout<<sum<<endl;
			continue;
		}
		/*
		cout<<endl;
		cout<<maxtid(a[k].f,a[k].s,a[k].t)<<endl;
		cout<<cnta[0]<<" "<<cnta[1]<<" "<<cnta[2]<<endl;
		for(int i = k;i < n;i++) printf("%d %d %d\n",a[i].f,a[i].s,a[i].t);
		cout<<endl;
		*/
		/*		
		sort(a+k,a+n,cmp2);
		
		//for(int i = k;i < n;i++) printf("%d %d %d\n",a[i].f,a[i].s,a[i].t);
		
		for(int i = k;i < n;i++) 
		if(maxtid(a[i].f,a[i].s,a[i].t) == maxtid(cnta[0],cnta[1],cnta[2])) sum += maxs(a[i].f,a[i].s,a[i].t);
		else sum += maxt(a[i].f,a[i].s,a[i].t);
		
		cout<<sum<<endl;
		*/
		
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
