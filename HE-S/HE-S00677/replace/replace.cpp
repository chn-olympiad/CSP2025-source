		if(b[1]<n/2)
		{
//			zs+=z[i][zz[i][1]];
//			js+=1;
			a[1]+=z[i][zz[i][1]];
			b[1]+=1;
			continue;
		}
		if(b[2]<n/2)
		{
//			zs+=z[i][zz[i][2]];
//			jss+=1;
			a[2]+=z[i][zz[i][2]];
			b[2]+=2;
			continue;
		}
		if(b[3]<n/2)
		{
//			zs+=z[i][zz[i][3]];
//			a[3]+=z[i][zz[i][3]];
			b[3]+=3;
			continue;
		}
