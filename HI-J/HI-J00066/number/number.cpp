#include<bits/stdc++.h>
using namespace std;

int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	int a,b,c,d,e,f,g;
	int x[10];
	int ans;
	int n;
	cin >> n;
	if(n<10)
	{
		ans=1;
		cout << n;
	} 
	else if(n >= 10 && n < 100)
	{
		ans = 2;
		g = n % 10;
		f = n / 10;
		if(g >= f)
		{
			x[1] = g;
			x[2] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else
		{
			cout << f << g;
		}
	}
	else if(n >= 100 && n < 1000)
	{
		ans = 3;
		g = n % 10;
		f = n % 100 /10;
		e = n / 100;
		if(g >= f && g >= e && f >= e)
		{
			x[1] = g;
			x[2] = f;
			x[3] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(g >= f &&g >= e&&e >= f)
		{
			x[1] = g;
			x[2] = e;
			x[3] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(f >= g &&f >= e&& g >= e)//efg,egf,feg
		{
			x[1] = f;
			x[2] = g;
			x[3] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(f >= g &&f >= e && e >= g)//efg,egf
		{
			x[1] = f;
			x[2] = e;
			x[3] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= g &&e >=f&& g>= f)//efg
		{
			x[1] = e;
			x[2] = g;
			x[3] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= g &&e >= f&& f>= g)//efg
		{
			x[1] = e;
			x[2] = f;
			x[3] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}	
	}
	else if(n >= 1000 && n < 10000)
	{
		ans = 4;
		g = n % 10;
		f = n % 100 /10;
		e = n % 1000 /100;
		d = n /1000;
		if(g >= d && d >= e && e >= f)//defg,degf,dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,gdef,gdfe,gedf,gefd,gfed,gfde
		{
			x[1] = g;
			x[2] = d;
			x[3] = e;
			x[4] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(g >= d && d >= f && f >= e)//gedf,gefd,gfed,gfde,defg,degf,dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = g;
			x[2] = d;
			x[3] = f;
			x[4] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(g >= e && e >= d && d >= f)//gefd,gfed,gfde,defg,degf,dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = g;
			x[2] = e;
			x[3] = d;
			x[4] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(g >= e && e >= f && f >= d)//gfed,gfde,defg,degf,dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = g;
			x[2] = e;
			x[3] = f;
			x[4] = d;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(g >= f && f >= e && e >= d)//gfed,gfde,defg,degf,dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = g;
			x[2] = f;
			x[3] = e;
			x[4] = d;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(g >= f && f >= d && d >= e)//defg,degf,dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = g;
			x[2] = f;
			x[3] = d;
			x[4] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
			else if(d >= e && e >= f && f >= g)//degf,dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = d;
			x[2] = e;
			x[3] = f;
			x[4] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
			else if(d >= e && e >= g && g >= f)//dfeg,dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = d;
			x[2] = e;
			x[3] = g;
			x[4] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(d >= f && f >= e && e >= g)//dfge,dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = d;
			x[2] = f;
			x[3] = e;
			x[4] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(d >= f && f >= g && g >= e)//dgef,dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = d;
			x[2] = f;
			x[3] = g;
			x[4] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(d >= g && g >= e && e >= f)//dgfe,edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = d;
			x[2] = g;
			x[3] = e;
			x[4] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(d >= g && g >= f && f >= e)//edgf,edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = d;
			x[2] = g;
			x[3] = f;
			x[4] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= d && d >= g && g >= f)//edfg,egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = e;
			x[2] = d;
			x[3] = g;
			x[4] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= d && d >= f && f >= g)//egdf,egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = e;
			x[2] = d;
			x[3] = f;
			x[4] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= g && g >= d && d >= f)//egfd,efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = e;
			x[2] = g;
			x[3] = d;
			x[4] = f;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= g && g >= f && f >= d)//efgd,efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = e;
			x[2] = g;
			x[3] = f;
			x[4] = d;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= f && f >= g && g >= d)//efdg,fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = e;
			x[2] = f;
			x[3] = g;
			x[4] = d;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(e >= f && f >= d && d >= g)//fdeg,fdge,fedg,fegd,fged,fgde,
		{
			x[1] = e;
			x[2] = f;
			x[3] = d;
			x[4] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(f >= d && d >= e && e >= g)//fdge,fedg,fegd,fged,fgde,
		{
			x[1] = f;
			x[2] = d;
			x[3] = e;
			x[4] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(f >= d && d >= g && g >= e)//fedg,fegd,fged,fgde,
		{
			x[1] = f;
			x[2] = d;
			x[3] = g;
			x[4] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(f >= e && e >= d && d >= g)//fegd,fged,fgde,
		{
			x[1] = f;
			x[2] = e;
			x[3] = d;
			x[4] = g;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
			else if(f >= e && e >= g && g >= d)//fged,fgde,
		{
			x[1] = f;
			x[2] = e;
			x[3] = g;
			x[4] = d;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(f >= g && g >= e && e >= d)//fgde,
		{
			x[1] = f;
			x[2] = g;
			x[3] = e;
			x[4] = d;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		else if(f >= g && g >= d && d >= e)//fgde,
		{
			x[1] = f;
			x[2] = g;
			x[3] = d;
			x[4] = e;
			for(int i = 1;i <= ans;i++)
			{
				cout << x[i];
			}
		}
		
		
		
		
	}
	return 0;
}

