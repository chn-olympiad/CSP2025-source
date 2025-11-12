#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;

struct aqwe{
	int aa;
	int ab;
	int ac;
};

bool mysort(aqwe a,aqwe b)
{
	return  max({a.aa,a.ab,a.ac})>max({b.aa,b.ab,b.ac}); 
}

struct use{
	int aa;
	int ab;
	int ac;
};
int fen(aqwe qwe)
{
return max({qwe.aa,qwe.ab,qwe.ac}); 
 } 
bool te(int used,int n,int a,int b)//used表示用了几个人，n表示一共几个人 ,a指此时的元素，b指将要加的地方的下一个元素
{
if(n-used==1&&a<b) return true;//表示需要特殊处理。即不在这一步选择最大
return false;
} 
bool tee(int a,int b,int c,int d)//a指此时的元素，b指第二大的元素，c指此时元素的下一个,d表示下一个第二大 
{
return (b+d)>(a+c); 
} 
void doo(){
	int n;
	cin>>n;
	aqwe man[N];//每个人对于3个协会分别的满意度 
	use used;//计数每个协会分了几人 
	int sum=0;//计数最大满意度 
	for(int i=0;i<n;i++)
	{
		cin>>man[i].aa>>man[i].ab>>man[i].ac;
	}
	
		sort(man,man+n,mysort);	
		
		for(int i=0;i<n;i++)//存入最大值 
	{
	if(fen(man[i])==man[i].aa)//并列情况1 
	{
		if(used.aa+1<=(n/2))//判断能否存 
		{
			if(!tee(man[i].aa,max(man[i].ab,man[i].ac),man[i+1].aa,max(man[i+1].ab,man[i+1].ac)))
			{
				used.aa++;
			sum+=fen(man[i]);
			}
			else
			{
				int ce=max(man[i].ab,man[i].ac);
			if(ce==man[i].ab)
			{
				if(used.ab+1<=(n/2)&&!te(used.ab,n/2,ce,man[i+1].ab))
				{
					used.ab++;
				sum+=ce;	
				}
				
			else{
				used.ac++;
				sum+=ce;
			}
			 }
			 
			if(ce==man[i].ac)
			{
				if(used.ac+1<=(n/2)&&!te(used.ac,n/2,ce,man[i+1].ac))
				{
					used.ac++;
				sum+=ce;	
				}
			else
			{
				used.ab++;
				sum+=ce;
			}
			 } 	
			}
		}
		else{
			int ce=max(man[i].ab,man[i].ac);
			if(ce==man[i].ab)
			{
				if(used.ab+1<=(n/2)&&!te(used.ab,n/2,ce,man[i+1].ab))
				{
					used.ab++;
				sum+=ce;	
				}
				
			else{
				used.ac++;
				sum+=ce;
			}
			 }
			 
			if(ce==man[i].ac)
			{
				if(used.ac+1<=(n/2)&&!te(used.ac,n/2,ce,man[i+1].ac))
				{
					used.ac++;
				sum+=ce;	
				}
			else
			{
				used.ab++;
				sum+=ce;
			}
			 } 	 
		}
	}
		if(fen(man[i])==man[i].ab)//并列情况2
	{
		if(used.ab+1<=(n/2))//判断能否存 
		{
		if(!tee(man[i].ab,max(man[i].aa,man[i].ac),man[i+1].ab,max(man[i+1].aa,man[i+1].ac)))
			{
			used.ab++;
			sum+=fen(man[i]);
			}
		else{
				int ce=max(man[i].aa,man[i].ac);
			if(ce==man[i].aa)
			{
				if(used.aa+1<=(n/2)&&!te(used.aa,n/2,ce,man[i+1].aa))
				{
					used.aa++;
				sum+=ce;	
				}
			else
			{
				used.ac++;
				sum+=ce;
			}
			 }
			 
			if(ce==man[i].ac)
			{
				if(used.ac+1<=(n/2)&&!te(used.ac,n/2,ce,man[i+1].ac))
				{
					used.ac++;
				sum+=ce;	
				}
			else
			{
				used.aa++;
				sum+=ce;
			}
			 } 
		}	
			
		}
		else{
			int ce=max(man[i].aa,man[i].ac);
			if(ce==man[i].aa)
			{
				if(used.aa+1<=(n/2)&&!te(used.aa,n/2,ce,man[i+1].aa))
				{
					used.aa++;
				sum+=ce;	
				}
			else
			{
				used.ac++;
				sum+=ce;
			}
			 }
			 
			if(ce==man[i].ac)
			{
				if(used.ac+1<=(n/2)&&!te(used.ac,n/2,ce,man[i+1].ac))
				{
					used.ac++;
				sum+=ce;	
				}
			else
			{
				used.aa++;
				sum+=ce;
			}
			 } 	 
		}
	}
		if(fen(man[i])==man[i].ac)//并列情况3 
	{
		if(used.ac+1<=(n/2))//判断能否存 
		{
				if(!tee(man[i].ac,max(man[i].aa,man[i].ab),man[i+1].ac,max(man[i+1].aa,man[i+1].ab)))
			{
			used.ac++;
			sum+=fen(man[i]);
			}
		else{
				int ce=max(man[i].ab,man[i].aa);
			if(ce==man[i].ab)
			{
				if(used.ab+1<=(n/2)&&!te(used.ab,n/2,ce,man[i+1].ab))
				{
					used.ab++;
				sum+=ce;	
				}
			else
			{
				used.aa++;
				sum+=ce;
			}
			 }
			 
			if(ce==man[i].aa)
			{
				if(used.aa+1<=(n/2)&&!te(used.aa,n/2,ce,man[i+1].aa))
				{
					used.aa++;
				sum+=ce;	
				}
			else
			{
				used.ab++;
				sum+=ce;
			}
			 } 
		}
		}
		else{
			int ce=max(man[i].ab,man[i].aa);
			if(ce==man[i].ab)
			{
				if(used.ab+1<=(n/2)&&!te(used.ab,n/2,ce,man[i+1].ab))
				{
					used.ab++;
				sum+=ce;	
				}
			else
			{
				used.aa++;
				sum+=ce;
			}
			 }
			 
			if(ce==man[i].aa)
			{
				if(used.aa+1<=(n/2)&&!te(used.aa,n/2,ce,man[i+1].aa))
				{
					used.aa++;
				sum+=ce;	
				}
			else
			{
				used.ab++;
				sum+=ce;
			}
			 } 	 
		}
	}
	cout<<sum<<"&&"<<endl;
	}
		cout<<sum<<endl;	
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=0;i<t;i++)
{
	doo();
}
	return 0;
 } 

